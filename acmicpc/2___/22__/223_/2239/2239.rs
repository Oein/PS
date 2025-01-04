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

fn solve(
    board: &mut Vec<Vec<u8>>,
    row: &mut Vec<Vec<bool>>,
    col: &mut Vec<Vec<bool>>,
    square: &mut Vec<Vec<bool>>,
    x: u8,
    y: u8,
) -> bool {
    if y == 9 {
        // solve done
        return true;
    }

    if board[y as usize][x as usize] != 0 {
        let mut next_x = x + 1;
        let mut next_y = y;
        if next_x == 9 {
            next_x = 0;
            next_y += 1;
        }
        return solve(board, row, col, square, next_x, next_y);
    }

    for num in 1..10 {
        if row[y as usize][num as usize] {
            continue;
        }

        if col[x as usize][num as usize] {
            continue;
        }

        if square[((y / 3) * 3 + x / 3) as usize][num as usize] {
            continue;
        }

        row[y as usize][num as usize] = true;
        col[x as usize][num as usize] = true;
        square[((y / 3) * 3 + x / 3) as usize][num as usize] = true;
        board[y as usize][x as usize] = num;

        let mut next_x = x + 1;
        let mut next_y = y;
        if next_x == 9 {
            next_x = 0;
            next_y += 1;
        }

        if solve(board, row, col, square, next_x, next_y) {
            return true;
        }

        row[y as usize][num as usize] = false;
        col[x as usize][num as usize] = false;
        square[((y / 3) * 3 + x / 3) as usize][num as usize] = false;
        board[y as usize][x as usize] = 0;
    }

    return false;
}

fn solution(io: &mut RustIO, stdout: &mut String) {
    let mut board: Vec<Vec<u8>> = vec![vec![0; 9]; 9];
    let mut row: Vec<Vec<bool>> = vec![vec![false; 10]; 9];
    let mut col: Vec<Vec<bool>> = vec![vec![false; 10]; 9];
    let mut square: Vec<Vec<bool>> = vec![vec![false; 10]; 9];

    for i in 0..9 {
        let line = io.read_words_vecu8();
        for j in 0..9 {
            board[i][j] = line[j] - b'0';
            if board[i][j] != 0 {
                row[i][board[i][j] as usize] = true;
                col[j][board[i][j] as usize] = true;
                square[(i / 3) * 3 + j / 3][board[i][j] as usize] = true;
            }
        }
    }

    solve(&mut board, &mut row, &mut col, &mut square, 0, 0);

    for i in 0..9 {
        for j in 0..9 {
            write!(stdout, "{}", board[i][j]).unwrap();
        }
        writeln!(stdout).unwrap();
    }
}

fn main() {
    let mut io = RustIO::new();
    let mut stdout = String::new();

    solution(&mut io, &mut stdout);

    // Program ends here

    print!("{}", stdout);
}
