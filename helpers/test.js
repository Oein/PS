const path = require("path");
const fs = require("fs");
const { exec, execSync, execFile, spawn } = require("child_process");

const chlx = require("./chalk").default;
var term = require("terminal-kit").terminal;
const chl = new chlx(term);
const { PRO } = require("./const");

const crypto = require("crypto");
const { default: gfp } = require("./getFilePath");

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
 * @param {{type:"cpp"|"py"|"js";number:number;service:"jungol"|"acmicpc"|"nypc"|"biko"|"custom";}} ans
 * @returns
 */
const run = async (ans) => {
  const ansn = ans.number.toString();
  const ansTwo = ansn.slice(0, ansn.length - 2);
  let fp = path.join(__dirname, "..", ans.service, gfp(ans.number));

  // 저장된 폴더
  if (ans.service == "custom") {
    fp = path.join(__dirname, "..", "custom", ans.number);
  }
  if (!fs.existsSync(fp)) {
    chl.error("문제 폴더가 존재하지 않습니다.");
    term.processExit(1);
  }

  // 소스코드 파일 경로
  const filePath = path.join(fp, ans.number + "." + ans.type);
  const getCPH = () => {
    const CPH_DIR = path.join(fp, ".cph");
    if (!fs.existsSync(CPH_DIR)) {
      chl.error("CPH 폴더가 존재하지 않습니다.");
      term.processExit(1);
      return;
    }
    const files = fs
      .readdirSync(CPH_DIR)
      .filter((x) => x.startsWith(`.${ansn}.${ans.type}_`));
    if (files.length == 0) {
      chl.error("CPH 파일이 존재하지 않습니다.");
      term.processExit(1);
      return;
    }
    return files[0];
  };
  const cphPath = getCPH();

  // 소스코드 파일이 존재하지 않을 경우
  // cph 파일이 존재하지 않을 경우
  if (!fs.existsSync(filePath)) {
    chl.error("소스코드 파일이 존재하지 않습니다.");
    term.processExit(1);
  }

  if (!fs.existsSync(cphPath)) {
    chl.error("CPH 파일이 존재하지 않습니다");
    term.processExit(1);
  }

  const commandSet = commands[ans.type];

  const buildOUTPUTPath = cphPath.replace(".prob", ".out");

  // 빌드
  if (commandSet.build) {
    chl.loading("");
    const spinner = await term.spinner("bitDots");
    term(" 빌드중...");
    execSync(
      commandSet.build
        .replace("$OUT", buildOUTPUTPath)
        .replace("$SRC", filePath),
      {
        stdio: "pipe",
      }
    );
    spinner.animate(0);
    term("\n");
    chl.success("빌드 성공!\n");
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

  chl.loading("");
  const pgbar = term.progressBar({
    width: 80,
    eta: true,
    percent: true,
    title: "테스트 진행중",
  });

  let results = [];

  let i = 0;
  let allSuccess = true;
  for (const test of CPH.tests) {
    i++;
    await new Promise((res) => {
      let isTOUT = false;
      const child = spawn(
        commandSet.run.replace("$SRC", cphPath).replace("$OUT", buildOUTPUTPath)
      );
      const tout = setTimeout(
        () => {
          isTOUT = true;
          child.kill();
          results.push({
            type: "timeout",
          });
          allSuccess = false;
          fs.writeFileSync(
            path.join(fp, "run_" + i + ".expected"),
            test.output
          );
          fs.writeFileSync(path.join(fp, "run_" + i + ".received"), buf);
          res();
        },
        CPH.timeLimit == 0 ? 1000 : CPH.timeLimit
      );
      child.stdin.write(test.input);
      child.stdin.end();
      let buf = "";
      child.stdout.on("data", (data) => {
        buf += data.toString();
      });
      child.stdout.on("end", () => {
        if (isTOUT) return;
        clearTimeout(tout);
        if (matcher(buf, test.output)) {
          results.push({
            type: "success",
          });
        } else {
          allSuccess = false;
          results.push({
            type: "fail",
          });
          fs.writeFileSync(
            path.join(fp, "run_" + i + ".expected"),
            test.output
          );
          fs.writeFileSync(path.join(fp, "run_" + i + ".received"), buf);
        }
        res();
      });
    });
    pgbar.update(i / CPH.tests.length);
  }

  pgbar.stop();

  term("\n");

  if (allSuccess) {
    chl.info("테스트 결과\n");
    chl.success("모든 테스트를 통과했습니다.");
    term.processExit(0);
    return;
  }

  const origre = [...results];

  const colSel = () => {
    term.clear();
    chl.info("테스트 결과\n");
    results = [...origre];
    term.singleColumnMenu(
      [
        "Rerun",
        ...results.map((v, i) => {
          return v.type == "success"
            ? `#${i + 1} 테스트: 성공`
            : v.type == "fail"
            ? `#${i + 1} 테스트: 실패`
            : `#${i + 1} 테스트: 시간 초과`;
        }),
        "Exit",
      ],
      (err, arg) => {
        let idx = arg.selectedIndex;
        if (idx == results.length + 1) return term.processExit(0);
        if (idx == 0) {
          run(ans);
          return;
        }
        idx--;
        if (results[idx].type == "success") {
          colSel();
          return;
        }
        term("\n");
        execSync(
          `${PRO} --diff ${path.join(
            fp,
            "run_" + (idx + 1) + ".expected"
          )} ${path.join(fp, "run_" + (idx + 1) + ".received")}`
        );
        colSel();
      }
    );
  };
  colSel();
};

const main = () => {
  term.clear();
  const lastExsist = fs.existsSync(path.join(__dirname, "last.json"));
  const lastStr = () => {
    const last = JSON.parse(
      fs.readFileSync(path.join(__dirname, "last.json")).toString()
    );
    return `last (${last.service} / ${last.number}.${last.type})`;
  };
  chl.query("서비스를 선택하세요.");
  term.singleColumnMenu(
    [
      lastExsist ? lastStr() : "",
      "acmicpc",
      "jungol",
      "nypc",
      "biko",
      "custom",
    ].filter((x) => x.length > 0),
    (err, arg) => {
      const idx = arg.selectedIndex;

      if (idx == 0) {
        if (!fs.existsSync(path.join(__dirname, "last.json"))) {
          chl.error("마지막으로 사용한 파일이 없습니다.");
          term.processExit(1);
        }

        const last = JSON.parse(
          fs.readFileSync(path.join(__dirname, "last.json")).toString()
        );
        run(last);

        return;
      }

      chl.query("언어를 선택하세요.");
      term.singleColumnMenu(["cpp", "py", "js"], (err, larg) => {
        chl.query("문제 번호를 입력하세요: ");
        term.inputField({}, (err, num) => {
          run({
            service: arg.selectedText,
            type: larg.selectedText,
            number: num,
          });
        });
      });
    }
  );
};

main();
