#!node
const inq = require("inquirer");
const path = require("path");
const fs = require("fs");
const { execSync } = require("child_process");
const prompt = inq.createPromptModule();

/**
 *
 * @param {{type:"cpp"|"py"|"js";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko";}} ans
 * @returns
 */
const run = async (ans) => {
  const ansn = ans.number.toString();
  const ansTwo = ansn.slice(0, ansn.length - 2);
  const p = path.join(__dirname, "../", ans.service, ansTwo + "__");

  const fp = path.join(p, ans.number);
  if (!fs.existsSync(fp)) {
    console.log("파일이 존재하지 않습니다.");
    return;
  }
  console.log(
    execSync(
      `git add ${fp}; git commit -m "solve: ${ans.service} / ${ans.number}.${ans.type}"`
    ).toString()
  );
};

const main = () => {
  const last = JSON.parse(
    fs.readFileSync(path.join(__dirname, "last.json")).toString()
  );
  prompt({
    service: {
      type: "list",
      choices: [
        {
          name: `last (${last.service} / ${last.number}.${last.type})`,
          value: "last",
        },
        "jungol",
        "acmicpc",
        "nypc",
        "biko",
      ],
    },
  }).then((ansx) => {
    if (ansx.service == "last") {
      if (!fs.existsSync(path.join(__dirname, "last.json"))) {
        console.log("No last file");
        return;
      }
      run(last);
    } else
      prompt({
        type: {
          type: "list",
          choices: ["cpp", "py", "js"],
        },
        number: {
          type: "input",
          message: "문제 번호를 입력하세요.",
        },
      }).then((ansy) => {
        run({ ...ansx, ...ansy });
      });
  });
};

main();
