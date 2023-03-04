use std::io::Write;

fn main() {
    let stdin = std::io::stdin();
    let stdout = std::io::stdout();
    let mut scan = rw::stdio_scanner(&stdin);
    let mut out = rw::stdio_bufwriter(&stdout);

    let cases = scan.token::<i32>();
    for _ in 0..cases {
        let n = scan.token::<i32>();
        writeln!(out, "{}", (1 << n) - 1).ok();
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
