import crypto from "crypto";
import { Language, Service } from "./types";
import path from "path";

export default function getCPHPath(problem: {
  pid: string;
  service: Service;
  lang: Language;
  solutionPath: string;
}) {
  const hashlize = () => {
    const hash = crypto
      .createHash("md5")
      .update(path.resolve(problem.solutionPath))
      .digest("hex")
      .substr(0);
    return hash;
  };

  const f = path.join(
    problem.solutionPath,
    "..",
    ".cph",
    "." + problem.pid + "." + problem.lang + "_" + hashlize() + ".prob"
  );
  return f;
}
