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

        let buffer = buffer.clone();
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

    fn read_i64(&mut self) -> i64 {
        self.consume_whitespace();

        let is_negative = self.buffer[self.cursor] == b'-';
        if is_negative {
            self.cursor += 1;
        }

        let mut result = 0;
        while !self.buffer[self.cursor].is_ascii_whitespace() {
            result = result * 10 + (self.buffer[self.cursor] - b'0') as i64;
            self.cursor += 1;
        }

        if is_negative {
            result = -result;
        }

        result
    }

    fn read_f32(&mut self) -> f32 {
        self.consume_whitespace();

        let is_negative = self.buffer[self.cursor] == b'-';
        if is_negative {
            self.cursor += 1;
        }

        let mut result = 0.0;
        while !self.buffer[self.cursor].is_ascii_whitespace() {
            if self.buffer[self.cursor] == b'.' {
                self.cursor += 1;
                let mut decimal = 0.1;
                while !self.buffer[self.cursor].is_ascii_whitespace() {
                    result += (self.buffer[self.cursor] - b'0') as f32 * decimal;
                    decimal /= 10.0;
                    self.cursor += 1;
                }
                break;
            }
            result = result * 10.0 + (self.buffer[self.cursor] - b'0') as f32;
            self.cursor += 1;
        }

        if is_negative {
            result = -result;
        }

        result
    }

    fn read_f64(&mut self) -> f64 {
        self.consume_whitespace();

        let is_negative = self.buffer[self.cursor] == b'-';
        if is_negative {
            self.cursor += 1;
        }

        let mut result = 0.0;
        while !self.buffer[self.cursor].is_ascii_whitespace() {
            if self.buffer[self.cursor] == b'.' {
                self.cursor += 1;
                let mut decimal = 0.1;
                while !self.buffer[self.cursor].is_ascii_whitespace() {
                    result += (self.buffer[self.cursor] - b'0') as f64 * decimal;
                    decimal /= 10.0;
                    self.cursor += 1;
                }
                break;
            }
            result = result * 10.0 + (self.buffer[self.cursor] - b'0') as f64;
            self.cursor += 1;
        }

        if is_negative {
            result = -result;
        }

        result
    }

    fn read_words(&mut self) -> String {
        self.consume_whitespace();

        let start = self.cursor;
        while !self.buffer[self.cursor].is_ascii_whitespace() {
            self.cursor += 1;
        }

        String::from_utf8(self.buffer[start..self.cursor].to_vec()).unwrap()
    }

    fn read_words_vecu8(&mut self) -> Vec<u8> {
        self.consume_whitespace();

        let start = self.cursor;
        while !self.buffer[self.cursor].is_ascii_whitespace() {
            self.cursor += 1;
        }

        let result = self.buffer[start..self.cursor].to_vec();
        self.cursor += 1;
        result
    }

    fn read_line(&mut self) -> String {
        self.consume_whitespace();

        let start = self.cursor;
        while self.buffer[self.cursor] != b'\n' {
            self.cursor += 1;
        }

        self.cursor += 1;
        String::from_utf8(self.buffer[start..self.cursor].to_vec()).unwrap()
    }
}

fn apply_jinsu(n: i64, jinsu: i64) -> i64 {
    let nstr = n.to_string().chars().collect::<Vec<char>>();
    let mut result = 0;
    let mut j = 1;
    // println!("{} ", jinsu);
    for i in (0..3).rev() {
        result += (nstr[i] as i32 - b'0' as i32) as i64 * j;
        if i != 0 {
            j *= jinsu;
        }

        // print!("M ");
    }
    // println!();

    result
}

fn rmain(io: &mut RustIO) {
    let a = io.read_i64();
    let b = io.read_i64();

    let mut jinsu_x: i64 = 10;
    let mut jinsu_y: i64 = 10;

    while jinsu_x <= 15000 && jinsu_y <= 15000 {
        let ax = apply_jinsu(a, jinsu_x);
        let by = apply_jinsu(b, jinsu_y);

        if ax == by {
            println!("{} {}", jinsu_x, jinsu_y);
            return;
        }

        if ax < by {
            jinsu_x += 1;
        } else {
            jinsu_y += 1;
        }
    }
}

fn main() {
    let mut io = RustIO::new();
    let mut k = io.read_i32();

    while k > 0 {
        rmain(&mut io);
        k -= 1;
    }
}
