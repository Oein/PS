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

fn solution(io: &mut RustIO, stdout: &mut String) {
    let n = io.read_i32();
    let r = io.read_i32();
    let q = io.read_i32();

    let mut path: Vec<Vec<i32>> = vec![vec![]; n as usize + 1];

    for _ in 0..n - 1 {
        let u = io.read_i32();
        let v = io.read_i32();
        path[u as usize].push(v);
        path[v as usize].push(u);
    }

    let mut path_calculated: Vec<Vec<i32>> = vec![vec![]; n as usize + 1];

    let mut visited = vec![false; n as usize + 1];
    let mut queue = vec![r];
    visited[r as usize] = true;

    while !queue.is_empty() {
        let node = queue.pop().unwrap();
        for &child in path[node as usize].iter() {
            if !visited[child as usize] {
                visited[child as usize] = true;
                path_calculated[node as usize].push(child);
                queue.push(child);
            }
        }
    }

    let mut subtree_size = vec![0; n as usize + 1];

    fn dfs(node: i32, parent: i32, subtree_size: &mut Vec<i32>, path: &Vec<Vec<i32>>) -> i32 {
        subtree_size[node as usize] = 1;
        for &child in path[node as usize].iter() {
            if child == parent {
                continue;
            }
            subtree_size[node as usize] =
                subtree_size[node as usize] + dfs(child, node, subtree_size, path);
        }

        // println!("At {} size is {}", node, subtree_size[node as usize]);

        subtree_size[node as usize]
    }

    dfs(r, -1, &mut subtree_size, &path_calculated);

    for _ in 0..q {
        let u = io.read_i32();
        writeln!(stdout, "{}", subtree_size[u as usize]).unwrap();
    }
}

fn main() {
    let mut io = RustIO::new();
    let mut stdout = String::new();

    solution(&mut io, &mut stdout);

    // Program ends here

    print!("{}", stdout);
}
