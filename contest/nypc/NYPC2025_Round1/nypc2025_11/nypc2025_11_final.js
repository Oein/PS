// 최종 최적화 버전 - 메모리와 시간 모두 최적화
const fs = require("fs");

const dwn = ["", "만", "억", "조"];
const krn = ["", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구"];
const dxn = ["", "십", "백", "천"];

function num2kor(numx) {
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

// 최종 최적화 버전
function findKthSuperOptimized(n, k) {
  // 1단계: 각 첫 글자별 개수만 먼저 세기
  const charCounts = new Map();

  for (let i = 1; i <= n; i++) {
    const korStr = num2kor(i) + "주년";
    const firstChar = korStr[0];
    charCounts.set(firstChar, (charCounts.get(firstChar) || 0) + 1);
  }

  // 2단계: 사전순으로 정렬된 문자들
  const sortedChars = Array.from(charCounts.keys()).sort();

  // 3단계: k가 어느 그룹에 속하는지 찾기
  let cumulativeCount = 0;
  let targetChar = null;
  let startIndex = 0;

  for (const char of sortedChars) {
    const count = charCounts.get(char);
    if (cumulativeCount + count >= k) {
      targetChar = char;
      startIndex = k - cumulativeCount;
      break;
    }
    cumulativeCount += count;
  }

  // 4단계: 해당 그룹 내에서만 정렬해서 찾기
  const targetGroup = [];
  for (let i = 1; i <= n; i++) {
    const korStr = num2kor(i) + "주년";
    if (korStr[0] === targetChar) {
      targetGroup.push([korStr, i]);
    }
  }

  targetGroup.sort();
  return targetGroup[startIndex - 1][1];
}

// 입력 처리
if (require.main === module) {
  const input = fs.readFileSync(0, "utf-8").trim().split("\n");
  const [n, k] = input[0].split(" ").map(Number);

  const result = findKthSuperOptimized(n, k);
  process.stdout.write(result.toString());
}

// 테스트용 export
module.exports = { findKthSuperOptimized, num2kor };
