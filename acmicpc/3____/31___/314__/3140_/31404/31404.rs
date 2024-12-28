use std::{
    collections::HashSet,
    io::{stdin, Read},
    vec,
};

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

fn main() {
    let mut io = RustIO::new();

    let h = io.read_i32();
    let w = io.read_i32();
    let mut y = io.read_i32();
    let mut x = io.read_i32();
    let mut d = io.read_i32() as u8;

    let mut rule_tablea: Vec<Vec<u8>> = Vec::new();
    for _ in 0..h {
        rule_tablea.push(io.read_words_vecu8());
    }

    let mut rule_tableb: Vec<Vec<u8>> = Vec::new();
    for _ in 0..h {
        rule_tableb.push(io.read_words_vecu8());
    }

    // visited = [x, y, d]
    // if visited == true, cleaned
    let mut res: i64 = 0;
    let mut rm: i64 = 0;
    let dx = vec![0, 1, 0, -1];
    let dy = vec![-1, 0, 1, 0];

    let mut visited = vec![vec![vec![false; 4]; w as usize]; h as usize];
    let mut dust = vec![vec![true; w as usize]; h as usize];

    while x >= 0 && y >= 0 && x < w && y < h {
        if dust[y as usize][x as usize] {
            dust[y as usize][x as usize] = false;
            d = rule_tablea[y as usize][x as usize] - b'0' + d;
            d %= 4;
            x += dx[d as usize];
            y += dy[d as usize];

            rm = 0;
            // reset visited
            visited = vec![vec![vec![false; 4]; w as usize]; h as usize];
        } else {
            d = rule_tableb[y as usize][x as usize] - b'0' + d;
            d %= 4;

            if visited[y as usize][x as usize][d as usize] {
                break;
            }
            rm += 1;
            visited[y as usize][x as usize][d as usize] = true;

            x += dx[d as usize];
            y += dy[d as usize];
        }

        res += 1;
    }

    res -= rm;

    print!("{}", res);
}
