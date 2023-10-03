#!/Users/dev/.nvm/versions/node/v16.20.1/bin/node
const inq = require("inquirer");
const path = require("path");
const fs = require("fs");
const { execSync } = require("child_process");
const prompt = inq.createPromptModule();

const { default: axios } = require("axios");
const { BSON } = require("bson");

const crypto = require("crypto");
const cheerio = require("cheerio");

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
  const ansTwo = ansn.slice(0, ansn.length - 2);
  const p = path.join(__dirname, "../", ans.service, ansTwo + "__", ".cph");
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
  const p = path.join(__dirname, "../", ans.service, ansTwo + "__", ".cph");
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
 * @param {{type:"cpp"|"py";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko";}} ans
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
 * @param {{type:"cpp"|"py";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko";}} ans
 */
const createJungolProblem = async (ans) => {
  const api = "https://api.jungol.co.kr/problem/1000";
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
  }).then(async (ans) => {
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
    if (!hasCPH(ans)) await createCPH(ans);
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
};

main();
