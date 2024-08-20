let fs = require("fs");
let path = require("path");
const { default: gfp } = require("./getFilePath");
const BASEDIR = path.join(__dirname, "..", "jungol_new");
fs.mkdirSync(BASEDIR, {
  recursive: true,
});
const wk = (p) => {
  let files = fs.readdirSync(p);
  for (let file of files) {
    if (file == ".cph") continue;
    if (file == ".git") continue;
    if (file == ".DS_Store") continue;
    let stat = fs.statSync(p + "/" + file);
    if (stat.isDirectory()) {
      let fil = fs.readdirSync(p + "/" + file);
      for (let f of fil) {
        if (f == ".cph") continue;
        if (f == ".git") continue;
        if (f == ".DS_Store") continue;
        const gp = gfp(f);
        fs.mkdirSync(path.join(BASEDIR, gp, ".."), {
          recursive: true,
        });
        // copy from p + "/" + file + "/" + f to BASEDIR + "/" + gp
        fs.cpSync(path.join(p, file, f), path.join(BASEDIR, gp), {
          recursive: true,
        });
      }
    }
    // if (stat.isDirectory()) {
    //   wk(p + "/" + file);
    // } else {
    //   console.log(p, file);
    //   fs.mkdirSync(path.join(p, file.split(".")[0]), {
    //     recursive: true,
    //   });
    //   fs.renameSync(path.join(p, file), path.join(p, file.split(".")[0], file));
    //   fs.writeFileSync(
    //     path.join(p, file.split(".")[0], "README.md"),
    //     "# " + file.split(".")[0]
    //   );
    // }
  }
};

wk(path.join(__dirname, "..", "jungol"));
