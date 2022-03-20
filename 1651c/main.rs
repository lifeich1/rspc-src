use std::io::Write;

fn get_cost(x: i64, a: &[i64]) -> i64 {
    a.iter().map(|y| (x - y).abs()).min().unwrap()
}

fn main() {
    let stdin = std::io::stdin();
    let stdout = std::io::stdout();
    let mut scan = rw::stdio_scanner(&stdin);
    let mut out = rw::stdio_bufwriter(&stdout);

    let cases = scan.token::<i32>();
    let mut a: [i64; 201001] = [0; 201001];
    let mut b: [i64; 201001] = [0; 201001];
    for _ in 0..cases {
        let n = scan.token::<usize>();
        for i in 0..n {
            a[i] = scan.token();
        }
        for i in 0..n {
            b[i] = scan.token();
        }
        let mut f: [i64; 16] = [i64::MAX; 16];
        let mut c: Vec<(usize, i64)> = Vec::with_capacity(8);

        c.push((1, get_cost(a[0], &b[1..(n - 1)])));
        c.push((2, get_cost(a[n - 1], &b[1..(n - 1)])));
        c.push((4, get_cost(b[0], &a[1..(n - 1)])));
        c.push((8, get_cost(b[n - 1], &a[1..(n - 1)])));

        c.push((1 | 4, (a[0] - b[0]).abs()));
        c.push((1 | 8, (a[0] - b[n - 1]).abs()));
        c.push((2 | 4, (a[n - 1] - b[0]).abs()));
        c.push((2 | 8, (a[n - 1] - b[n - 1]).abs()));

        f[0] = 0;
        for i in 0..15 {
            for e in c.iter() {
                if i != (i | e.0) {
                    let j = i | e.0;
                    let v = f[i] + e.1;
                    if f[j] > v {
                        f[j] = v;
                    }
                }
            }
        }

        writeln!(out, "{}", f[15]).ok();
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
