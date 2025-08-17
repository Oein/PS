use std::io::stdin;
fn main() {
    let mut ix: String = String::new();
    stdin().read_line(&mut ix).unwrap();
    let spl: Vec<&str> = ix.split_whitespace().collect();

    let num1: i32 = spl[0].parse().expect("To be number");
    let num2: i32 = spl[1].parse().expect("To be number");

    print!("{}", num1 + num2)
}
