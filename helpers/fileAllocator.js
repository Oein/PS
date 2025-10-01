let fs = require("fs");
let path = require("path");
const { default: gfp } = require("./getFilePath");
const BASEDIR = path.join(__dirname, "..", "moved");
fs.mkdirSync(BASEDIR, {
  recursive: true,
});
const wk = (wpt) => {
  let files = fs.readdirSync(path.join(__dirname, "..", wpt));
  for (let file of files) {
    if (file == ".git") continue;
    if (file == ".DS_Store") continue;
    let stat = fs.statSync(path.join(__dirname, "..", wpt, file));
    if (stat.isDirectory()) {
      wk(wpt + "/" + file);
    } else {
      let newPath = path.join(BASEDIR, wpt.replace(/_/g, "x"));
      fs.mkdirSync(newPath, {
        recursive: true,
      });
      fs.copyFileSync(
        path.join(__dirname, "..", wpt, file),
        path.join(newPath, file)
      );
      console.log(newPath);
    }
  }
};

wk("acmicpc");
