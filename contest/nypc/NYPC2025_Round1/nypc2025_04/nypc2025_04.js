const fs = require("fs");
const input = fs.readFileSync(0, "utf-8").trim().split("\n");

const [n, m] = input[0].split(" ").map(Number);
const emojis = input.slice(1, n + 1);

let chat = input.slice(n + 1)[0];

while (true) {
  let midx = -1;
  let mat = -1;

  for (let i = 0; i < emojis.length; i++) {
    const idx = chat.indexOf(`:${emojis[i]}:`);
    if (idx != -1 && (midx == -1 || idx < midx)) {
      midx = idx;
      mat = i;
    }
  }

  if (midx == -1) {
    break;
  }

  chat = chat.replace(`:${emojis[mat]}:`, `[${emojis[mat]}]`);
}

let printedInThisLine = 0;
let cht = chat.split("");

for (let i = 0; i < cht.length; i++) {
  const now = cht[i];
  printedInThisLine++;

  if (now == "[") {
    process.stdout.write(now);
    i++;
    while (i < cht.length && cht[i] != "]") {
      process.stdout.write(cht[i]);
      i++;
    }
    process.stdout.write("]");
  } else {
    process.stdout.write(now);
  }

  if (printedInThisLine == m) {
    process.stdout.write("\n");
    printedInThisLine = 0;
  }
}
