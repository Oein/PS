import fs from "fs";
import child_process from "child_process";
import path from "path";
import { Language, noSplitFileServices, Service } from "./types";
import getFilePath from "./getFilePath";

async function runLastTS() {
  const lastPath = path.join(__dirname, "last.json");
  if (!fs.existsSync(lastPath)) {
    console.error("No last.json found.");
    process.exit(1);
  }

  const lastData: {
    language: Language;
    service: Service;
    problemId: string;
  } | null = JSON.parse(fs.readFileSync(lastPath, "utf-8"));

  if (!lastData) {
    console.error("Invalid last.json data.");
    process.exit(1);
  }

  const { language, service, problemId } = lastData;

  const solutionPath = noSplitFileServices.includes(service)
    ? `${service}/${problemId}/${problemId}.${language}`
    : service + "/" + getFilePath(problemId) + "/" + problemId + "." + language;

  if (language != "ts") {
    console.error("This script is intended for TypeScript files only.");
  }

  // bun run ${solutionPath}
  console.log(`bun run "${path.resolve(solutionPath)}"`);
  child_process.execSync(`bun run "${path.resolve(solutionPath)}"`, {
    stdio: "inherit",
  });
}

if (require.main === module) {
  runLastTS();
}
