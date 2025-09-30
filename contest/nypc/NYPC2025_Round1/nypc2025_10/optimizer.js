const fs = require("fs");

const Tile = {
  BOOSTER: "@",
  WALL: "#",
  EMPTY: ".",
  START: "S",
  END: "T",
};

/**
 *
 * @param {String[]} input
 */
function process(input) {
  const [h, w, itemCount] = input[0].split(" ").map(Number);
  const map = input.slice(1, h + 1).map((x) => x.split(""));

  console.log(map);

  const isNode = map.map((row, i) => {
    return row.map((cell, j) => {
      if (cell == Tile.BOOSTER || cell == Tile.START || cell == Tile.END) {
        return true;
      }
      if (cell == Tile.WALL) {
        return false;
      }
      const isEmpty = (x, y) => {
        return x >= 0 &&
          x < h &&
          y >= 0 &&
          y < w &&
          (map[x][y] == Tile.EMPTY ||
            map[x][y] == Tile.START ||
            map[x][y] == Tile.END ||
            map[x][y] == Tile.BOOSTER)
          ? 1
          : 0;
      };

      return (
        isEmpty(i - 1, j) +
          isEmpty(i + 1, j) +
          isEmpty(i, j - 1) +
          isEmpty(i, j + 1) >
        3
      );
    });
  });

  console.log(
    isNode
      .map((row) => row.map((cell) => (cell ? "O" : "X")).join(" "))
      .join("\n")
  );
}

process(
  fs
    .readFileSync(__dirname + "/input_5", "utf-8")
    .trim()
    .split("\n")
);
