export default function argumentParser<
  KeysT extends string | number | symbol = string
>(
  keys: (KeysT | [KeysT, "string" | "boolean" | "number"])[]
): {
  kv: { [key in KeysT]: string | boolean | number };
  globalParam: string | null;
} {
  let kv: { [key in KeysT]: string | boolean | number } = {} as any;
  let globalParam: string | null = null;

  let args = process.argv.slice(2);
  for (let i = 0; i < args.length; i++) {
    let arg = args[i];

    const flags = keys.map((k) => (Array.isArray(k) ? k[0] : k));

    let key = arg as KeysT;
    if (flags.includes(key)) {
      let type: "string" | "boolean" | "number" = "string";
      for (let k of keys) {
        if (Array.isArray(k) && k[0] === key) {
          type = k[1];
          break;
        }
      }
      if (type === "string") {
        i++;
        kv[key] = args[i];
      } else if (type === "number") {
        i++;
        kv[key] = Number(args[i]);
      } else {
        kv[key] = true;
      }
    } else {
      if (globalParam === null) {
        globalParam = arg;
      }
    }
  }

  return { kv, globalParam };
}
