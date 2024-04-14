let fs = require("fs");
let path = require("path");

const wk = (p) => {
  let files = fs.readdirSync(p);
  for (let file of files) {
    let stat = fs.statSync(p + "/" + file);
    if (file == ".cph") continue;
    if (file == ".git") continue;
    if (file == ".DS_Store") continue;
    if (stat.isDirectory()) {
      wk(p + "/" + file);
    } else {
      if (file != "README.md") continue;
      const content = fs.readFileSync(path.join(p, file)).toString();
      if (content.split("\n").length > 1) continue;
      const num = content.split("# ")[1];
      console.log(p, file, num);
      fs.writeFileSync(
        path.join(p, "README.md"),
        `# ${num}\n\nProblem from [jungol](https://jungol.co.kr/problem/${num})\n\n`
      );
    }
  }
};

wk(path.join(__dirname, "jungol"));
