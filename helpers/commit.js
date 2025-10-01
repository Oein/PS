const path = require("path");
const fs = require("fs");
const { execSync } = require("child_process");

const chlx = require("./chalk").default;
var term = require("terminal-kit").terminal;
const chl = new chlx(term);

const gfp = require("./getFilePath").default;

process.stdin.on("data", (data) => {
  if (data.toString() === "\u0003") term.processExit(0);
});

/**
 *
 * @param {{type:"cpp"|"py"|"js";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko"|"custom";}} ans
 * @returns
 */
const run = async (ans) => {
  let p = path.join(__dirname, "..", ans.service, gfp(ans.number));
  if (ans.service == "custom") {
    p = path.join(__dirname, "../", "custom", ans.number);
  }
  if (!fs.existsSync(p)) {
    chl.error("파일이 존재하지 않습니다.");
    term.processExit(1);
  }
  console.log(
    execSync(
      `git add ${p}; git commit -m "solve: ${ans.service} / ${ans.number}.${ans.type}"`
    ).toString()
  );
  term.processExit(0);
};

const main = async () => {
  term.clear();

  const problemNumber = process.argv[2];
  if (problemNumber) {
    if (!isNaN(problemNumber)) {
      const ans = {
        service: "acmicpc",
        type: "cpp",
        number: parseInt(problemNumber),
      };
      await run(ans);
      return;
    }
  }

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
      "acmicpc",
      "jungol",
      "nypc",
      "biko",
      "custom",
    ].filter((x) => x.length > 0),
    (err, arg) => {
      const idx = arg.selectedIndex;

      if (idx == 0) {
        if (!fs.existsSync(path.join(__dirname, "last.json"))) {
          chl.error("마지막으로 사용한 파일이 없습니다.");
          term.processExit(1);
        }
        const last = JSON.parse(
          fs.readFileSync(path.join(__dirname, "last.json")).toString()
        );
        run(last);

        return;
      }

      chl.query("언어를 선택하세요.");
      term.singleColumnMenu(["cpp", "py", "js", "rs"], (err, larg) => {
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
