#!node
const inq = require("inquirer");
const path = require("path");
const fs = require("fs");
const { exec, execSync, execFile, spawn } = require("child_process");
const prompt = inq.createPromptModule();

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

const commands = {
  cpp: {
    build: "g++ -std=c++17 -o $OUT $SRC",
    run: "$OUT",
  },
  py: {
    build: null,
    run: "python3 $SRC",
  },
  js: {
    build: null,
    run: "node $SRC",
  },
};

/**
 *
 * @param {{type:"cpp"|"py"|"js";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko";}} ans
 * @returns
 */
const run = async (ans) => {
  const ansn = ans.number.toString();
  const ansTwo = ansn.slice(0, ansn.length - 2);
  const p = path.join(__dirname, "..", ans.service, ansTwo + "__");

  // 저장된 폴더
  const fp = path.join(p, ans.number);
  if (!fs.existsSync(fp)) {
    console.log("파일이 존재하지 않습니다.");
    return;
  }

  // 소스코드 파일 경로
  const filePath = path.join(fp, ans.number + "." + ans.type);
  const cphPath = path.join(
    fp,
    ".cph",
    "." + ansn + "." + ans.type + "_" + rand(filePath) + ".prob",
  );

  // 소스코드 파일이 존재하지 않을 경우
  // cph 파일이 존재하지 않을 경우
  if (!fs.existsSync(filePath)) {
    console.log("파일이 존재하지 않습니다 FILE");
    return;
  }

  if (!fs.existsSync(cphPath)) {
    console.log("파일이 존재하지 않습니다 CPH");
    return;
  }

  const commandSet = commands[ans.type];

  const buildOUTPUTPath = cphPath.replace(".prob", ".out");

  // 빌드
  if (commandSet.build) {
    execSync(
      commandSet.build
        .replace("$OUT", buildOUTPUTPath)
        .replace("$SRC", filePath),
    );
    console.log("[Build ✅] Build Done");
  }

  // test
  const CPH = JSON.parse(fs.readFileSync(cphPath, "utf-8"));
  /*
  {
      "name": "Local: 17404",
      "url": "/Users/oein/oein/Pjs/C++/PS/acmicpc/174__/17404/17404.cpp",
      "tests": [
          {
              "input": "3\n26 40 83\n49 60 57\n13 89 99\n",
              "output": "110\n",
              "id": 1720861921963
          },
          {
              "input": "3\n1 100 100\n100 1 100\n100 100 1\n",
              "output": "3\n",
              "id": 1720861921863
          },
          {
              "input": "3\n1 100 100\n100 100 100\n1 100 100\n",
              "output": "201\n",
              "id": 1720861921763
          },
          {
              "input": "6\n30 19 5\n64 77 64\n15 19 97\n4 71 57\n90 86 84\n93 32 91\n",
              "output": "208\n",
              "id": 1720861921663
          },
          {
              "id": 1720861921563,
              "input": "8\n71 39 44\n32 83 55\n51 37 63\n89 29 100\n83 58 11\n65 13 15\n47 25 29\n60 66 19\n",
              "output": "253\n"
          }
      ],
      "interactive": false,
      "memoryLimit": 128,
      "timeLimit": 0,
      "srcPath": "/Users/oein/oein/Pjs/C++/PS/acmicpc/174__/17404/17404.cpp",
      "group": "local",
      "local": true
  }
  */

  const trimmer = (str) =>
    str
      .split("\n")
      .map((x) => x.trim())
      .filter((x) => x)
      .join("\n");

  const matcher = (a, b) => {
    return trimmer(a) == trimmer(b);
  };

  let i = 0;
  for (const test of CPH.tests) {
    i++;
    await new Promise((res) => {
      const child = spawn(
        commandSet.run
          .replace("$SRC", cphPath)
          .replace("$OUT", buildOUTPUTPath),
      );
      const tout = setTimeout(
        () => {
          child.kill();
          console.log(`[Test ${i} ⏰] Test Timeout`);
          res();
        },
        CPH.timeLimit == 0 ? 1000 : CPH.timeLimit,
      );
      child.stdin.write(test.input);
      let buf = "";
      child.stdout.on("data", (data) => {
        buf += data.toString();
      });
      child.stdout.on("end", () => {
        clearTimeout(tout);
        if (matcher(buf, test.output)) {
          console.log(`[Test ${i} ✅] Test Passed`);
        } else {
          console.log(`[Test ${i} ❌] Test Unmatch`);
          if (process.env.PRINTRES) {
            console.log("Expected ================================");
            console.log(test.output);
            console.log("Received ================================");
            console.log(buf);
          }
        }
        res();
      });
    });
  }
};

const main = () => {
  const last = JSON.parse(
    fs.readFileSync(path.join(__dirname, "last.json")).toString(),
  );
  prompt({
    service: {
      type: "list",
      choices: [
        {
          name: `last (${last.service} / ${last.number}.${last.type})`,
          value: "last",
        },
        "jungol",
        "acmicpc",
        "nypc",
        "biko",
      ],
    },
  }).then((ansx) => {
    if (ansx.service == "last") {
      if (!fs.existsSync(path.join(__dirname, "last.json"))) {
        console.log("No last file");
        return;
      }
      run(last);
    } else
      prompt({
        type: {
          type: "list",
          choices: ["cpp", "py", "js"],
        },
        number: {
          type: "input",
          message: "문제 번호를 입력하세요.",
        },
      }).then((ansy) => {
        run({ ...ansx, ...ansy });
      });
  });
};

main();
