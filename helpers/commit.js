#!/Users/dev/.nvm/versions/node/v16.20.1/bin/node
const inq = require("inquirer");
const path = require("path");
const fs = require("fs");
const { execSync } = require("child_process");
const prompt = inq.createPromptModule();

prompt({
  service: {
    type: "list",
    choices: ["jungol", "acmicpc", "nypc", "biko"],
  },
  type: {
    type: "list",
    choices: ["cpp", "py"],
  },
  number: {
    type: "input",
    message: "문제 번호를 입력하세요.",
  },
}).then((ans) => {
  const ansn = ans.number.toString();
  const ansTwo = ansn.slice(0, ansn.length - 2);
  const p = path.join(__dirname, "../", ans.service, ansTwo + "__");

  const fp = path.join(p, ans.number + "." + ans.type);
  if (!fs.existsSync(fp)) {
    console.log("파일이 존재하지 않습니다.");
    return;
  }
  console.log(
    execSync(
      `git add ${fp} && git commit -m "solve: ${ans.service} / ${ans.number}.${ans.type}"`
    ).toString()
  );
});
