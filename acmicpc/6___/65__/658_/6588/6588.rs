use std::io::{stdin, Read};

struct RustIO {
    buffer: Vec<u8>,
    cursor: usize,
}

#[allow(dead_code)]
impl RustIO {
    fn new() -> Self {
        let mut buffer = Vec::new();
        stdin().lock().read_to_end(&mut buffer).unwrap();

        let mut buffer = buffer.clone();

        // add \n to buffer for index out of bound by user input doesn't end with \n
        buffer.push(b'\n');
        Self { buffer, cursor: 0 }
    }
    fn consume_whitespace(&mut self) {
        while self.buffer[self.cursor].is_ascii_whitespace() {
            self.cursor += 1;
        }
    }
    fn read_i32(&mut self) -> i32 {
        self.consume_whitespace();

        let is_negative = self.buffer[self.cursor] == b'-';
        if is_negative {
            self.cursor += 1;
        }

        let mut result = 0;
        while !self.buffer[self.cursor].is_ascii_whitespace() {
            result = result * 10 + (self.buffer[self.cursor] - b'0') as i32;
            self.cursor += 1;
        }

        if is_negative {
            result = -result;
        }

        result
    }
}

fn main() {
    use std::fmt::Write;
    let mut io = RustIO::new();
    let mut stdout = String::new();

    let mut n = io.read_i32();

    let mut is_prime: Vec<bool> = vec![true; 1000001];
    is_prime[0] = false;
    is_prime[1] = false;

    for i in 2..1000001 {
        if is_prime[i] {
            let mut j = i * 2;
            while j < 1000001 {
                is_prime[j] = false;
                j += i;
            }
        }
    }

    loop {
        if n == 0 {
            break;
        }

        for i in 3..n + 1 {
            if i > n - i {
                write!(stdout, "Goldbach's conjecture is wrong.\n").unwrap();
                break;
            }
            if is_prime[i as usize] && is_prime[(n - i) as usize] {
                write!(stdout, "{} = {} + {}\n", n, i, n - i).unwrap();
                break;
            }
        }

        n = io.read_i32();
    }

    print!("{}", stdout);
}
