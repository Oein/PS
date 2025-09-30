const fs = require("fs");
const input = fs.readFileSync(0, "utf-8").trim().split("\n");
const [n, k] = input[0].split(" ").map(Number);
// const n = 100000;
const dwn = ["", "만", "억", "조"];
const krn = ["", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구"];
const dxn = ["", "십", "백", "천"];

function num2kor(numx) {
  /**
   * @type {String}
   */
  const num = numx.toString();
  const firstN = num.length % 4;
  const sp = [num.slice(0, firstN)].filter((x) => !!x);
  for (let i = firstN; i < num.length; i += 4) {
    sp.push(num.slice(i, i + 4));
  }
  return sp
    .map((x, i) => {
      const ddx = x.split("").map((y, j) => {
        const kn = krn[parseInt(y)];
        if (kn == "") return "";
        if (y == "1" && j == x.length - 1) return kn;
        if (y == "1") return dxn[x.length - 1 - j];
        return kn + dxn[x.length - 1 - j];
      });
      if (!ddx) return "";
      const dwnc = dwn[sp.length - i - 1];
      return ddx.join("") + dwnc;
    })
    .join("");
}

// [123, 12345, 1234567, 12345678, 1234567890].forEach((x) =>
//   console.log(num2kor(x))
// );

let items = [];
for (let i = 1; i <= n; i++) {
  items.push([num2kor(i) + "주년", i]);
  //   num2kor(i);
}

items = items.sort();

// console.log(+items[k - 1][1]);
process.stdout.write((+items[k - 1][1]).toString());
// console.log(items);
