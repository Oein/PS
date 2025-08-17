import chalk from "chalk";

class Logger {
  termfuc;
  constructor(tf) {
    this.termfuc = tf;
  }
  timeStr() {
    const now = new Date();
    return `${now.getHours().toString().padStart(2, "0")}:${now
      .getMinutes()
      .toString()
      .padStart(2, "0")}:${now.getSeconds().toString().padStart(2, "0")}`;
  }
  colorTime() {
    return `[${this.timeStr()}]`;
  }
  log(...args) {
    this.termfuc(this.colorTime(), chalk.gray("(default) "), ...args);
  }
  info(...args) {
    this.termfuc(this.colorTime(), chalk.blue("(   info) "), ...args);
  }
  success(...args) {
    this.termfuc(this.colorTime(), chalk.green("(success) "), ...args);
  }
  warn(...args) {
    console.log(this.colorTime(), chalk.yellow("(   warn) "), ...args);
  }
  error(...args) {
    this.termfuc(this.colorTime(), chalk.red("(  error) "), ...args);
  }
  query(...args) {
    this.termfuc(this.colorTime(), chalk.gray("(  query) "), ...args);
  }
  loading(...args) {
    this.termfuc(this.colorTime(), chalk.gray("(loading) "), ...args);
  }
}

export default Logger;
