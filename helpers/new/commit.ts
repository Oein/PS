import { terminal } from "terminal-kit";
import argumentParser from "./argumentParser";
import { Language, Languages, noSplitFileServices, Service } from "./types";
import chlkterm from "./chalk";
import getBasePath from "./getFilePath";
import { getBoj, ProbData } from "./probData";
import crypto from "crypto";
import path from "path";
import fs from "fs";
import child_process from "child_process";
import { get } from "http";
import getCPHPath from "./cphPath";

const chl = new chlkterm(terminal);
process.stdin.on("data", (data) => {
  if (data.toString() === "\u0003") terminal.processExit(0);
});

const args = argumentParser([
  ["--lang", "string"],
  ["-l", "string"],
  ["--cpp", "boolean"],
  ["-c", "boolean"],
  ["--ts", "boolean"],
  ["-t", "boolean"],
  ["--py", "boolean"],
  ["-py", "boolean"],
  ["--js", "boolean"],
  ["-js", "boolean"],
  ["--rs", "boolean"],
  ["-rs", "boolean"],

  ["--platform", "string"],
  ["--service", "string"],
  ["-s", "string"],
  ["--acmicpc", "boolean"],
  ["-a", "boolean"],
  ["--jungol", "boolean"],
  ["-j", "boolean"],
  ["--custom", "boolean"],

  ["--problem", "string"],
  ["-p", "string"],

  ["last", "boolean"],
  ["--last", "boolean"],
]);

function terminalSelection(options: string[], prompt: string): Promise<string> {
  return new Promise((resolve) => {
    chl.query(prompt);
    terminal.singleColumnMenu(options, (error, response) => {
      resolve(options[response.selectedIndex]);
    });
  });
}

function hasProblemIdArg(): boolean {
  return (
    Boolean(args.kv["--problem"]) ||
    Boolean(args.kv["-p"]) ||
    Boolean(args.globalParam)
  );
}

async function getLanguage(lastStr?: string): Promise<string> {
  const langParm = args.kv["--lang"] || args.kv["-l"];
  if (langParm) {
    return langParm as Language;
  }
  if (args.kv["--cpp"] || args.kv["-c"]) {
    return "cpp";
  }
  if (args.kv["--ts"] || args.kv["-t"]) {
    return "ts";
  }
  if (args.kv["--py"] || args.kv["-py"]) {
    return "py";
  }
  if (args.kv["--js"] || args.kv["-js"]) {
    return "js";
  }
  if (args.kv["--rs"] || args.kv["-rs"]) {
    return "rs";
  }

  if (hasProblemIdArg()) return "cpp";

  const lang = await terminalSelection(
    [lastStr, ...Languages].filter((v) => typeof v == "string"),
    "언어를 선택하세요: "
  );
  return lang as Language;
}

async function getService(): Promise<Service> {
  const serviceParm =
    args.kv["--service"] || args.kv["-s"] || args.kv["--platform"];
  if (serviceParm) {
    return serviceParm as Service;
  }
  if (args.kv["--acmicpc"] || args.kv["-a"]) {
    return "acmicpc";
  }
  if (args.kv["--jungol"] || args.kv["-j"]) {
    return "jungol";
  }
  if (args.kv["--custom"]) {
    return "custom";
  }

  if (hasProblemIdArg()) return "acmicpc";

  const service = await terminalSelection(
    ["acmicpc", "jungol", "custom"],
    "플랫폼을 선택하세요: "
  );
  return service as Service;
}

async function getProblemId(): Promise<string> {
  const problemParm = args.kv["--problem"] || args.kv["-p"];
  if (problemParm) {
    return problemParm as string;
  }
  const globalParam = args.globalParam;
  if (globalParam) {
    return globalParam;
  }

  return new Promise((resolve) => {
    chl.query("문제 ID를 입력하세요: ");
    terminal.inputField({}, (error, input) => {
      resolve(input || getProblemId());
    });
  });
}

async function main() {
  let lastFlag = args.kv["last"] || args.kv["--last"];
  let lastData: {
    language: Language;
    service: Service;
    problemId: string;
  } | null = null;

  const lastPath = path.join(__dirname, "last.json");
  if (fs.existsSync(lastPath)) {
    lastData = JSON.parse(fs.readFileSync(lastPath, "utf-8"));
  } else {
    chl.error("No last.json found.");
    process.exit(1);
  }

  const lastStr = () => {
    if (!lastData) return undefined;
    return `last (${lastData?.service} / ${lastData?.problemId}.${lastData?.language})`;
  };

  let language =
    (lastFlag && lastData?.language) || (await getLanguage(lastStr()));
  lastFlag = lastFlag || language === lastStr();
  language = (lastFlag && lastData ? lastData.language : language) as Language;
  const service = (lastFlag && lastData?.service) || (await getService());
  const problemId = (lastFlag && lastData?.problemId) || (await getProblemId());

  const solutionPath = noSplitFileServices.includes(service)
    ? `${service}/${problemId}/${problemId}.${language}`
    : service + "/" + getBasePath(problemId) + "/" + problemId + "." + language;

  try {
    child_process.execSync(`git add "${path.resolve(solutionPath)}"`);
  } catch (e) {}
  // add .cph
  const cphPath = getCPHPath({
    pid: problemId,
    service: service,
    lang: language as Language,
    solutionPath: solutionPath,
  });
  try {
    child_process.execSync(`git add "${path.resolve(cphPath)}"`);
  } catch (e) {}

  const readmePath = path.join(path.dirname(solutionPath), "README.md");
  if (fs.existsSync(readmePath)) {
    try {
      child_process.execSync(`git add "${path.resolve(readmePath)}"`);
    } catch (e) {}
  }
  child_process.execSync(
    `git commit -m "solve: ${service} / ${problemId}.${language}"`
  );
  chl.success("Committed solution and .cph file to git.");
}

if (require.main === module) {
  main().finally(() => {
    terminal.grabInput(false);
    setTimeout(() => {
      process.exit(0);
    }, 100);
  });
}

export default main;
