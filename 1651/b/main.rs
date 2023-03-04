use std::io::Write;

const LIM: i64 = 1000_000_000;

fn main() {
    let stdin = std::io::stdin();
    let stdout = std::io::stdout();
    let mut scan = rw::stdio_scanner(&stdin);
    let mut out = rw::stdio_bufwriter(&stdout);

    let cases = scan.token::<i32>();

    let mut a: Vec<i64> = Vec::new();
    let mut x: i64 = 1;
    while x < LIM {
        a.push(x);
        x *= 3;
    }

    for _ in 0..cases {
        let n = scan.token::<usize>();
        if n <= a.len() {
            writeln!(out, "YES").ok();
            for i in 0..(n - 1) {
                write!(out, "{} ", a[i]).ok();
            }
            writeln!(out, "{}", a[n - 1]).ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }

}

mod rw {
    use std::{io, str};
    
    pub struct Scanner<R> {
        reader: R,
        buffer: Vec<String>,
    }
    
    impl<R: io::BufRead> Scanner<R> {
        pub fn new(reader: R) -> Self {
            Self {
                reader,
                buffer: Default::default(),
            }
        }
    
        pub fn token<T: str::FromStr>(&mut self) -> T {
            loop {
                if let Some(t) = self.buffer.pop() {
                    return t.parse().ok().expect("Failed parse");
                }
                let mut line = String::new();
                self.reader.read_line(&mut line).expect("Failed read_line");
                self.buffer = line.split_whitespace().rev().map(String::from).collect();
            }
        }
    }
    
    pub fn stdio_scanner(stdin: &io::Stdin) -> Scanner<io::StdinLock> {
        Scanner::new(stdin.lock())
    }
    
    pub fn stdio_bufwriter(stdout: &io::Stdout) -> io::BufWriter<io::StdoutLock> {
        io::BufWriter::new(stdout.lock())
    }
    
}
