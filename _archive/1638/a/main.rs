use std::io::Write;

fn main() {
    let stdin = std::io::stdin();
    let stdout = std::io::stdout();
    let mut scan = rw::stdio_scanner(&stdin);
    let mut out = rw::stdio_bufwriter(&stdout);

    let cases = scan.token::<u32>();
    let mut a: [usize; 512] = [0; 512];
    for _ in 0..cases {
        let n = scan.token::<usize>();
        for i in 0..n {
            a[i] = scan.token::<usize>();
        }
        let mut l:usize = 0;
        let mut r:usize = 0;
        for i in 0..n {
            if i + 1 != a[i] {
                l = i + 1;
                break;
            }
        }
        if l > 0 {
            for i in l..n {
                if l == a[i] {
                    r = i;
                    break;
                }
            }
            l -= 1;
            while l < r {
                np::swap(&mut a, l, r);
                l += 1;
                r -= 1;
            }
        }
        for i in 0..n - 1 {
            write!(out, "{} ", a[i]).ok();
        }
        writeln!(out, "{}", a[n - 1]).ok();
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
mod np {
    pub fn swap<T: Copy + std::ops::BitXorAssign>(a: &mut [T], x: usize, y: usize) {
        a[x] ^= a[y];
        a[y] ^= a[x];
        a[x] ^= a[y];
    }
    
}
