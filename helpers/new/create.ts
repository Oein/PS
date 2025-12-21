import { terminal } from "terminal-kit";
import argumentParser from "./argumentParser";
import { Language, Languages, noSplitFileServices, Service } from "./types";
import chlkterm from "./chalk";
import getBasePath from "./getFilePath";
import { getBoj, ProbData } from "./probData";
import crypto from "crypto";
import path from "path";
import fs, { existsSync } from "fs";
import child_process from "child_process";
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

async function getLanguage(): Promise<Language> {
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

  const lang = await terminalSelection(Languages, "언어를 선택하세요: ");
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

async function getProbData(
  pid: string,
  service: Service
): Promise<ProbData | null> {
  if (service == "acmicpc") return getBoj(pid);
  return null;
}

async function saveCPH(
  prob: ProbData,
  problem: {
    pid: string;
    service: Service;
    lang: Language;
    solutionPath: string;
  }
) {
  const f = getCPHPath(problem);
  const dir = path.dirname(f);
  if (!fs.existsSync(dir)) {
    fs.mkdirSync(dir, { recursive: true });
  }

  chl.log("Saving CPH problem data to " + f);
  fs.writeFileSync(
    f,
    JSON.stringify({
      name: "Local: " + problem.pid,
      url: path.resolve(problem.solutionPath),
      tests: prob.samples.map((v, i) => {
        return {
          ...v,
          id: Date.now() - i * 100,
        };
      }),

      interactive: false,
      memoryLimit: prob.memory,
      timeLimit: prob.milisec,
      srcPath: path.resolve(problem.solutionPath),
      group: "local",
      local: true,
    })
  );
}

async function setupCPH(problem: {
  pid: string;
  service: Service;
  lang: Language;
  solutionPath: string;
}) {
  const cphPath = getCPHPath(problem);
  if (fs.existsSync(cphPath)) {
    chl.log("CPH problem data already exists at " + cphPath);
    return;
  }
  const probData = await getProbData(problem.pid, problem.service);
  if (probData) {
    await saveCPH(probData, problem);
  }
}

async function setupCodeFile(solutionPath: string, lang: Language) {
  if (existsSync(solutionPath)) {
    chl.log("Solution file already exists at " + solutionPath);
    return;
  }
  const template = path.join(__dirname, "template", lang + "." + lang);
  if (fs.existsSync(template)) {
    const content = fs.readFileSync(template, "utf-8");
    fs.writeFileSync(solutionPath, content);
    chl.success("Created solution file from template at " + solutionPath);
  } else {
    fs.writeFileSync(solutionPath, "");
    chl.success("Created empty solution file at " + solutionPath);
  }
}

async function setupMarkdownFile(problem: {
  pid: string;
  service: Service;
  lang: Language;
  solutionPath: string;
}) {
  const mdPath = path.join(path.dirname(problem.solutionPath), "README.md");

  if (fs.existsSync(mdPath)) {
    chl.log("Markdown file already exists at " + mdPath);
    return;
  }

  const data = ["# Problem " + problem.pid];
  if (problem.service == "acmicpc")
    data.push(
      "[Problem Link](https://www.acmicpc.net/problem/" + problem.pid + ")"
    );
  else data.push("Problem from " + problem.service);

  fs.writeFileSync(mdPath, data.join("\n"));
}

async function main() {
  const language = await getLanguage();
  const service = await getService();
  const problemId = await getProblemId();

  const solutionPath = noSplitFileServices.includes(service)
    ? `${service}/${problemId}/${problemId}.${language}`
    : service + "/" + getBasePath(problemId) + "/" + problemId + "." + language;

  chl.log("Creating solution file at " + solutionPath);

  await setupCPH({
    pid: problemId,
    service: service,
    lang: language,
    solutionPath: solutionPath,
  });
  await setupCodeFile(solutionPath, language);
  await setupMarkdownFile({
    pid: problemId,
    service: service,
    lang: language,
    solutionPath: solutionPath,
  });

  // open code
  child_process.exec(`code "${path.resolve(solutionPath)}"`);

  fs.writeFileSync(
    path.join(__dirname, "last.json"),
    JSON.stringify({
      language,
      service,
      problemId,
    })
  );

  return { language, service, problemId };
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
