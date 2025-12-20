import axios from "axios";
import * as cheerio from "cheerio";

export type ProbData = {
  samples: {
    input: string;
    output: string;
  }[];
  milisec: number;
  memory: number;
};

export async function getBoj(pid: string): Promise<ProbData> {
  let x = await axios.get("https://www.acmicpc.net/problem/" + pid.toString(), {
    headers: {
      "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64)",
    },
  });
  let $ = cheerio.load(x.data);
  let samples = [];
  for (let i = 1; i <= 10; i++) {
    try {
      let ipt = $("#sample-input-" + i.toString()).text();
      let opt = $("#sample-output-" + i.toString()).text();
      if (!ipt || !opt) break;
      samples.push({ input: ipt, output: opt });
      console.log("Sample " + i.toString() + " found.");
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
  console.log("Performance limit", data);
  return data;
}
