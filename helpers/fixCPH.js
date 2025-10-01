let fs = require("fs");
let path = require("path");

const crypto = require("crypto");
/**
 *
 * @param {string} srcPath
 * @returns
 */
const rand = (srcPath) => {
  const hash = crypto.createHash("md5").update(srcPath).digest("hex").substr(0);
  return hash;
};

const toIgnore = [".git", ".DS_Store", "helpers", "moved"];
const wk = (wpt) => {
  let files = fs.readdirSync(wpt);
  for (let file of files) {
    if (toIgnore.includes(file)) continue;
    let stat = fs.statSync(path.join(wpt, file));
    if (stat.isDirectory()) {
      wk(path.join(wpt, file));
    } else {
      // check if wpt ends with .cph
      if (wpt.endsWith(".cph") && file.endsWith(".prob")) {
        const origFileName = file.split("_").slice(0, -1).join("_").slice(1);
        const origFilePath = path.join(wpt, "..", origFileName);
        if (fs.existsSync(origFilePath)) {
          // read cph
          const cph = JSON.parse(
            fs.readFileSync(path.join(wpt, file)).toString()
          );
          const mergeContent = {
            url: origFilePath,
            srcPath: origFilePath,
          };
          const newCph = { ...cph, ...mergeContent };
          const newCCPHFILENAME = path.join(
            wpt,
            "." + origFileName + "_" + rand(origFilePath) + ".prob"
          );
          fs.writeFileSync(newCCPHFILENAME, JSON.stringify(newCph));
          console.log("Updated .cph file:", newCCPHFILENAME);
          // delete old cph
          fs.unlinkSync(path.join(wpt, file));
        }
      }
    }
  }
};

wk(path.join(__dirname, ".."));
