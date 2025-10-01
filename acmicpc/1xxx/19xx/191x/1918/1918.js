const fs = require("fs");
const stdin = fs.readFileSync(0).toString();
const stdout = process.stdout;

let input = "";
function parseCase(cursor) {
  const stack = [];
  let result = "";
  const precedence = {
    "+": 1,
    "-": 1,
    "*": 2,
    "/": 2,
  };

  while (cursor < input.length) {
    const char = input[cursor];
    if (char === "(") {
      const [newCursor, subResult] = parseCase(cursor + 1);
      result += subResult;
      cursor = newCursor;
    } else if (char === ")") {
      while (stack.length) {
        result += stack.pop();
      }
      return [cursor + 1, result];
    } else if (/[A-Z]/.test(char)) {
      result += char;
      cursor++;
    } else if (["+", "-", "*", "/"].includes(char)) {
      while (
        stack.length &&
        precedence[stack[stack.length - 1]] >= precedence[char]
      ) {
        result += stack.pop();
      }
      stack.push(char);
      cursor++;
    } else {
      cursor++;
    }
  }
  while (stack.length) {
    result += stack.pop();
  }

  stdout.write(result);
  return [cursor, result];
}

function main() {
  input = stdin.trim();
  parseCase(0);
}

main();
