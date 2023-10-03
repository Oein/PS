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
  if (!fs.existsSync(p)) {
    fs.mkdirSync(p, {
      recursive: true,
    });
  }

  let code = "";
  const fp = path.join(p, ans.number + "." + ans.type);
  if (!fs.existsSync(fp)) {
    if (fs.existsSync(path.join(__dirname, "template." + ans.type)))
      code = fs
        .readFileSync(path.join(__dirname, "template." + ans.type))
        .toString();
    fs.writeFileSync(fp, code);
  }
  execSync(`code ${fp}`);
  fs.writeFileSync(
    path.join(__dirname, "last.json"),
    JSON.stringify({
      service: ans.service,
      type: ans.type,
      number: ans.number,
    })
  );
});
