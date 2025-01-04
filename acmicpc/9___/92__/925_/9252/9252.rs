use std::fmt::Write;
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
        result
    }

    fn read_line(&mut self) -> String {
        self.consume_whitespace();

        let start = self.cursor;
        while self.buffer[self.cursor] != b'\n' {
            self.cursor += 1;
        }

        String::from_utf8(self.buffer[start..self.cursor].to_vec()).unwrap()
    }
}

fn get_lcs(str1: Vec<u8>, str2: Vec<u8>) -> Vec<u8> {
    let mut lcsubstring = vec![vec![0; str2.len() + 1]; str1.len() + 1];

    // lcs[i][j] = i번째까지의 str1과 j번째까지의 str2의 최장 공통 부분 문자열의 길이
    for i in 1..str1.len() + 1 {
        for j in 1..str2.len() + 1 {
            // 같으면 이전까지 만든 string에 더 추가할 수 있음.
            if str1[i - 1] == str2[j - 1] {
                lcsubstring[i][j] = lcsubstring[i - 1][j - 1] + 1;
            } else {
                // 다르면 이전까지 만든 string 중 가장 긴 것을 선택, 지금 사용할 문자는 버림
                lcsubstring[i][j] = lcsubstring[i - 1][j].max(lcsubstring[i][j - 1]);
            }
        }
    }

    // lcs를 찾아야 함.
    let mut lcs = Vec::new();
    let mut i = str1.len();
    let mut j = str2.len();

    loop {
        if i == 0 || j == 0 {
            break;
        }

        // 지금과 같은 길이를 가진 곳으로 이동.
        // 만약 같은 곳이 없는경우 -1, -1에서 더했다는 소리이기 때문에 lcs에 포함된 문자임.

        let now = lcsubstring[i][j];
        let up = lcsubstring[i - 1][j];
        let left = lcsubstring[i][j - 1];

        if now == up {
            i -= 1;
            continue;
        }
        if now == left {
            j -= 1;
            continue;
        }

        // 같은 문자가 있으면 lcs에 추가
        lcs.push(str1[i - 1]);
        i -= 1;
        j -= 1;
    }

    lcs.reverse();
    lcs
}

fn solution(io: &mut RustIO, stdout: &mut String) {
    let str1 = io.read_words_vecu8();
    let str2 = io.read_words_vecu8();

    let lcs = get_lcs(str1, str2);

    writeln!(stdout, "{}", lcs.len()).unwrap();
    for c in lcs {
        write!(stdout, "{}", c as char).unwrap();
    }

    // writeln!(stdout, "{}", lcs.len()).unwrap();
    // for c in lcs {
    //     write!(stdout, "{} ", c).unwrap();
    // }
}

fn main() {
    let mut io = RustIO::new();
    let mut stdout = String::new();
    solution(&mut io, &mut stdout);
    print!("{}", stdout);
}
