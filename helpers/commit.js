const path = require("path");
const fs = require("fs");
const { execSync } = require("child_process");

const chlx = require("./chalk").default;
var term = require("terminal-kit").terminal;
const chl = new chlx(term);

/**
 *
 * @param {{type:"cpp"|"py"|"js";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko"|"custom";}} ans
 * @returns
 */
const run = async (ans) => {
  const ansn = ans.number.toString();
  const ansTwo = ansn.slice(0, ansn.length - 2);
  let p = path.join(__dirname, "../", ans.service, ansTwo + "__");
  if (ans.service == "custom") {
    p = path.join(__dirname, "../", "custom");
  }

  const fp = path.join(p, ans.number);
  if (!fs.existsSync(fp)) {
    chl.error("파일이 존재하지 않습니다.");
    process.exit(1);
  }
  console.log(
    execSync(
      `git add ${fp}; git commit -m "solve: ${ans.service} / ${ans.number}.${ans.type}"`
    ).toString()
  );
  process.exit(0);
};

const main = () => {
  term.clear();
  const lastExsist = fs.existsSync(path.join(__dirname, "last.json"));
  const lastStr = () => {
    const last = JSON.parse(
      fs.readFileSync(path.join(__dirname, "last.json")).toString()
    );
    return `last (${last.service} / ${last.number}.${last.type})`;
  };
  chl.query("서비스를 선택하세요.");
  term.singleColumnMenu(
    [
      lastExsist ? lastStr() : "",
      "jungol",
      "acmicpc",
      "nypc",
      "biko",
      "custom",
    ].filter((x) => x.length > 0),
    (err, arg) => {
      const idx = arg.selectedIndex;

      if (idx == 0) {
        if (!fs.existsSync(path.join(__dirname, "last.json"))) {
          chl.error("마지막으로 사용한 파일이 없습니다.");
          process.exit(1);
        }
        const last = JSON.parse(
          fs.readFileSync(path.join(__dirname, "last.json")).toString()
        );
        run(last);

        return;
      }

      chl.query("언어를 선택하세요.");
      term.singleColumnMenu(["cpp", "py", "js"], (err, larg) => {
        chl.query("문제 번호를 입력하세요: ");
        term.inputField({}, (err, num) => {
          run({
            service: arg.selectedText,
            type: larg.selectedText,
            number: num,
          });
        });
      });
    }
  );
};

main();
