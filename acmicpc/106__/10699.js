let a = new Date();
const p = (x) => (x < 10 ? "0" + x : x);
console.log(a.getFullYear() + "-" + p(a.getMonth() + 1) + "-" + a.getDate());
