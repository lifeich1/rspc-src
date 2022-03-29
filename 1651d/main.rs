use std::io::Write;

fn main() {
    let stdin = std::io::stdin();
    let stdout = std::io::stdout();
    let mut scan = rw::stdio_scanner(&stdin);
    let mut out = rw::stdio_bufwriter(&stdout);

    let n = scan.token::<usize>();
    const N: usize = 201001;
    const N0: i32 = 200000;
    let mut xs: [i32; N] = [0; N];
    let mut ys: [i32; N] = [0; N];
    for i in 0..n {
        xs[i] = scan.token();
        ys[i] = scan.token();
    }

}

#[derive(Clone)]
struct KTreeNode {
    r0: usize,
    son: Vec<Option<KTreeNode>>,

    xmin: i32,
    xmax: i32, // [xmin, xmax)
    ymin: i32,
    ymax: i32,
    cnt: usize,
    cap: usize,
}

impl KTreeNode {
    fn new(r0: usize, xmin: i32, xmax: i32, ymin: i32, ymax: i32) -> Self {
        Self {
            r0,
            son: std::iter::repeat(None).take(r0).collect(),
            xmin, xmax,
            ymin, ymax,
            cnt: 0,
            cap: ((xmax - xmin) * (ymax - ymin)) as usize,
        }
    }

    fn son_new(&self, i: usize) -> Self {
        let xmid = (self.xmin + self.xmax) >> 1;
        let ymid = (self.ymin + self.ymax) >> 1;
        let xs = if (i & 2) == 0 {(self.xmin, xmid)} else {(xmid, self.xmax)};
        let ys = if (i & 1) == 0 {(self.ymin, ymid)} else {(ymid, self.ymax)};
        Self::new(self.r0, xs.0, xs.1, ys.0, ys.1)
    }

    fn son(&mut self, i: usize) -> &mut Self {
        if matches!(self.son[i], None) {
            self.son[i] = Some(self.son_new(i));
        }
        self.son[i].as_mut().unwrap()
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
