let fs = require("fs");
let path = require("path");
let inp = fs
  .readFileSync(path.join(__dirname, "27904msg"), "utf-8")
  .toString()
  .replace(/ /g, "")
  .replace(/\n/g, "");

// doit

let res = "";
let tab = 0;

const crTab = () => {
  let t = "";
  for (let i = 0; i < tab; i++) t += "  ";
  return t;
};

let yx = false;
const doAction = () => {
  if (inp.startsWith("만일")) {
    // if statement
    const idx = inp.indexOf("라면");
    const statement = inp.slice(2, idx);
    inp = inp.slice(idx + 2);
    const hang = statement.charAt(0);
    const yul = statement.charAt(2);
    const data = statement.charAt(statement.length - 1);

    res += crTab() + `if(b[${hang}][${yul}]=='${data}')`;
  } else if (inp.startsWith("아니고")) {
    // else statement
    const idx = inp.indexOf("라면");
    const statement = inp.slice(3, idx);
    inp = inp.slice(idx + 2);

    const hang = statement.charAt(0);
    const yul = statement.charAt(2);
    const data = statement.charAt(statement.length - 1);
    res += crTab() + `else if(b[${hang}][${yul}]=='${data}')`;
  } else if (inp.startsWith("아니라면")) {
    // else
    res += crTab() + `else`;
    yx = true;
    inp = inp.slice(4);
  } else if (inp.startsWith(",")) {
    res += "{\n";
    tab++;
    inp = inp.slice(1);
  } else if (inp.startsWith(".")) {
    res += `\n${crTab()}}\n`;
    //if(!yx)tab--;
    if (yx) res += `\n${crTab()}}\n`;
    yx = false;
    inp = inp.slice(1);
  } else if (inp.startsWith("O")) {
    // O가이겼습니다
    tab++;
    res += `{\n${crTab()}r=0;`;
    tab--;
    inp = inp.slice(7);
  } else if (inp.startsWith("X")) {
    // X가이겼습니다
    tab++;
    res += `{\n${crTab()}r=1;`;
    tab--;
    inp = inp.slice(7);
  }
};

while (inp.length > 0) {
  doAction();
}

fs.writeFileSync(
  path.join(__dirname, "res.cpp"),
  `int main() {\nint b[5][5] = {0,};\nint r=2;\n${res}\n}`
);
