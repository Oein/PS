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
      console.log(p, file);
      fs.mkdirSync(path.join(p, file.split(".")[0]), {
        recursive: true,
      });
      fs.renameSync(path.join(p, file), path.join(p, file.split(".")[0], file));
      fs.writeFileSync(
        path.join(p, file.split(".")[0], "README.md"),
        "# " + file.split(".")[0]
      );
    }
  }
};

wk(path.join(__dirname, "acmicpc"));
