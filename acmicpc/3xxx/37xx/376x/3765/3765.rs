#![allow(unused_imports)]
use std::fmt::Write;
use std::io::{stdin, Read};
use std::vec;

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
        while self.has_now() && self.buffer[self.cursor].is_ascii_whitespace() {
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
        while self.has_now() && !self.buffer[self.cursor].is_ascii_whitespace() {
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
        while self.has_now() && !self.buffer[self.cursor].is_ascii_whitespace() {
            result = result * 10 + (self.buffer[self.cursor] - b'0') as i64;
            self.cursor += 1;
        }

        if is_negative {
            result = -result;
        }

        result
    }

    fn read_u128(&mut self) -> u128 {
        self.consume_whitespace();

        let mut result = 0;
        while self.has_now() && !self.buffer[self.cursor].is_ascii_whitespace() {
            result = result * 10 + (self.buffer[self.cursor] - b'0') as u128;
            self.cursor += 1;
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
        while self.has_now() && !self.buffer[self.cursor].is_ascii_whitespace() {
            if self.buffer[self.cursor] == b'.' {
                self.cursor += 1;
                let mut decimal = 0.1;
                while self.has_now() && !self.buffer[self.cursor].is_ascii_whitespace() {
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
        while self.has_now() && !self.buffer[self.cursor].is_ascii_whitespace() {
            if self.buffer[self.cursor] == b'.' {
                self.cursor += 1;
                let mut decimal = 0.1;
                while self.has_now() && !self.buffer[self.cursor].is_ascii_whitespace() {
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
        while self.has_now() && !self.buffer[self.cursor].is_ascii_whitespace() {
            self.cursor += 1;
        }

        String::from_utf8(self.buffer[start..self.cursor].to_vec()).unwrap()
    }

    fn read_words_vecu8(&mut self) -> Vec<u8> {
        self.consume_whitespace();

        let start = self.cursor;
        while self.has_now() && !self.buffer[self.cursor].is_ascii_whitespace() {
            self.cursor += 1;
        }

        let result = self.buffer[start..self.cursor].to_vec();
        result
    }

    fn read_line(&mut self) -> String {
        self.consume_whitespace();

        let start = self.cursor;
        while self.has_now() && self.buffer[self.cursor] != b'\n' {
            self.cursor += 1;
        }

        String::from_utf8(self.buffer[start..self.cursor].to_vec()).unwrap()
    }

    fn has_next(&self) -> bool {
        self.cursor + 1 < self.buffer.len()
    }

    fn has_now(&self) -> bool {
        self.cursor < self.buffer.len()
    }
}

#[allow(unused_variables)]
fn solution(io: &mut RustIO, stdout: &mut String) {
    while io.has_next() {
        let str = io.read_line();
        writeln!(stdout, "{}", str).unwrap();
    }
}

// ========================================================

fn main() {
    let mut io = RustIO::new();
    let mut stdout = String::new();
    solution(&mut io, &mut stdout);
    print!("{}", stdout);
}
