const path = require("path");
const fs = require("fs");
const { execSync } = require("child_process");

const { default: axios } = require("axios");
const { BSON } = require("bson");

const crypto = require("crypto");
const cheerio = require("cheerio");
const { PRO } = require("./const");

const chlx = require("./chalk").default;
var term = require("terminal-kit").terminal;
const chl = new chlx(term);

const gfp = require("./getFilePath").default;

process.stdin.on("data", (data) => {
  if (data.toString() === "\u0003") term.processExit(0);
});

/**
 *
 * @param {string} srcPath
 * @returns
 */
const rand = (srcPath) => {
  const hash = crypto.createHash("md5").update(srcPath).digest("hex").substr(0);
  return hash;
};

/**
 *
 * @param {{type:"cpp"|"py";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko";}} ans
 */
const hasCPH = (ans) => {
  const ansn = ans.number.toString();
  const p = path.join(__dirname, "../", ans.service, gfp(ans), ".cph");
  const f = path.join(
    p,
    "." +
      ansn +
      "." +
      ans.type +
      "_" +
      rand(path.join(p, "..", ansn + "." + ans.type)) +
      ".prob"
  );
  return fs.existsSync(f);
};

/**
 *
 * @param {{type:"cpp"|"py";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko";}} ans
 * @param {{in:string;out:string;}[]} example
 * @param {number} memory
 * @param {number} time
 */
const createProp = async (ans, example, memory, time) => {
  const ansn = ans.number.toString();
  const ansTwo = ansn.slice(0, ansn.length - 2);
  const p = path.join(__dirname, "../", ans.service, gfp(ans.number), ".cph");
  const f = path.join(
    p,
    "." +
      ansn +
      "." +
      ans.type +
      "_" +
      rand(path.join(p, "..", ansn + "." + ans.type)) +
      ".prob"
  );

  if (!fs.existsSync(p))
    fs.mkdirSync(p, {
      recursive: true,
    });
  fs.writeFileSync(
    f,
    JSON.stringify({
      name: "Local: " + ansn,
      url: path.join(p, "..", ansn + "." + ans.type),
      tests: example.map((v, i) => {
        return {
          ...v,
          id: Date.now() - i * 100,
        };
      }),

      interactive: false,
      memoryLimit: memory,
      timeLimit: time,
      srcPath: path.join(p, "..", ansn + "." + ans.type),
      group: "local",
      local: true,
    })
  );
};

/**
 *
 * @param {{type:"cpp"|"py"|"js";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko";}} ans
 */
const createAcmicpcProblem = async (ans) => {
  async function getBoj(pid) {
    let x = await axios.get(
      "https://www.acmicpc.net/problem/" + pid.toString(),
      {
        headers: {
          "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64)",
        },
      }
    );
    let $ = cheerio.load(x.data);
    let samples = [];
    for (let i = 1; i <= 10; i++) {
      try {
        let ipt = $("#sample-input-" + i.toString()).text();
        let opt = $("#sample-output-" + i.toString()).text();
        if (!ipt || !opt) break;
        samples.push({ input: ipt, output: opt });
      } catch (e) {
        break;
      }
    }
    let milisec = -1,
      memory = -1;

    $("#problem-info > tbody > tr > td").each((i, e) => {
      if (i == 0) milisec = parseInt($(e).text().split(" ")[0]) * 1000;
      else if (i == 1) memory = parseInt($(e).text().split(" ")[0]);
    });
    let data = {
      samples: samples,
      milisec: milisec,
      memory: memory,
    };
    return data;
  }
  const data = await getBoj(ans.number);
  createProp(ans, data.samples, data.memory, data.milisec);
};

/**
 *
 * @param {{type:"cpp"|"py"|"js";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko";}} ans
 */
const createJungolProblem = async (ans) => {
  const api = "https://api.jungol.co.kr/problem/" + ans.number.toString();
  axios
    .get(api, {
      responseType: "arraybuffer",
    })
    .then((res) => {
      const dt = BSON.deserialize(res.data);
      const { limit, example } = dt.data;
      createProp(ans, example, limit.memory, limit.time);
    });
};
/**
 *
 * @param {{type:"cpp"|"py";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko";}} ans
 */
const createCPH = async (ans) => {
  if (ans.service == "jungol") await createJungolProblem(ans);
  if (ans.service == "acmicpc") await createAcmicpcProblem(ans);
  return;
};

const main = () => {
  chl.query("서비스를 선택하세요.");
  term.singleColumnMenu(
    ["acmicpc", "jungol", "nypc", "biko", "custom"],
    (err, arg) => {
      const idx = arg.selectedIndex;

      chl.query("언어를 선택하세요.");
      term.singleColumnMenu(["cpp", "py", "js", "rs"], (err, larg) => {
        chl.query("문제 번호를 입력하세요: ");
        term.inputField({}, async (err, num) => {
          const ans = {
            service: arg.selectedText,
            type: larg.selectedText,
            number: num,
          };

          let p = path.join(__dirname, "..", ans.service, gfp(ans.number));
          if (ans.service == "custom")
            p = path.join(__dirname, "..", "custom", ans.number);
          if (!hasCPH(ans)) await createCPH(ans);
          if (!fs.existsSync(p)) {
            fs.mkdirSync(p, {
              recursive: true,
            });
          }

          let code = "";
          const fp = path.join(p, ans.number + "." + ans.type);
          if (!fs.existsSync(fp)) {
            if (fs.existsSync(path.join(__dirname, "__tp." + ans.type)))
              code = fs
                .readFileSync(path.join(__dirname, "__tp." + ans.type))
                .toString();
            fs.writeFileSync(fp, code);
          }
          const md = path.join(p, "README.md");
          if (!fs.existsSync(md)) {
            if (ans.service == "custom") {
              fs.writeFileSync(md, `# Custom Problem ${ans.number}\n\n`);
            } else
              fs.writeFileSync(
                md,
                "# " +
                  ans.number +
                  "\n\nProblem from [" +
                  ans.service +
                  "](" +
                  (() => {
                    if (ans.service == "jungol")
                      return "https://jungol.co.kr/problem/" + ans.number;
                    if (ans.service == "acmicpc")
                      return "https://www.acmicpc.net/problem/" + ans.number;
                    return "";
                  })() +
                  ")\n\n"
              );
          }
          execSync(`${PRO} ${fp}`);
          fs.writeFileSync(
            path.join(__dirname, "last.json"),
            JSON.stringify({
              service: ans.service,
              type: ans.type,
              number: ans.number,
            })
          );
          term.processExit(0);
        });
      });
    }
  );
};

main();
