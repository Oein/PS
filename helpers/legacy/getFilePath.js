const pth = require("path");
const gfp = (number) => {
  const nstr = number.toString();
  const len = nstr.length;
  const path = [];
  for (let i = 0; i < len; i++) {
    path.push(nstr.slice(0, i) + nstr[i] + "x".repeat(len - i - 1));
  }
  return path.join(pth.sep);
};

export default gfp;
