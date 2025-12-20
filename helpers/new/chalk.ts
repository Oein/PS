import chalk from "chalk";

class Logger {
  termfuc;
  constructor(tf: any = console.log) {
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
  log(...args: any[]) {
    this.termfuc(this.colorTime(), chalk.gray("(default) "), ...args, "\n");
  }
  info(...args: any[]) {
    this.termfuc(this.colorTime(), chalk.blue("(   info) "), ...args, "\n");
  }
  success(...args: any[]) {
    this.termfuc(this.colorTime(), chalk.green("(success) "), ...args, "\n");
  }
  warn(...args: any[]) {
    console.log(this.colorTime(), chalk.yellow("(   warn) "), ...args, "\n");
  }
  error(...args: any[]) {
    this.termfuc(this.colorTime(), chalk.red("(  error) "), ...args, "\n");
  }
  query(...args: any[]) {
    this.termfuc(this.colorTime(), chalk.gray("(  query) "), ...args, "\n");
  }
  loading(...args: any[]) {
    this.termfuc(this.colorTime(), chalk.gray("(loading) "), ...args, "\n");
  }
}

export default Logger;
