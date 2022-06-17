use std::io::Write;

macro_rules! real_trace {
    ($($tail:tt)*) => {
        {
            let stdout = std::io::stdout();
            let mut out = rw::stdio_bufwriter(&stdout);
            writeln!(out, $($tail)*).ok();
        }
    };
}

macro_rules! trace {
    ($($tail:tt)*) => {
        //real_trace!($($tail)*)
    };
}

const R0: i32 = 0;
const R1: i32 = 200_002;

fn main() {
    let stdin = std::io::stdin();
    let stdout = std::io::stdout();
    let mut scan = rw::stdio_scanner(&stdin);
    let mut out = rw::stdio_bufwriter(&stdout);

    let n = scan.token::<usize>();
    const N: usize = 201_001;
    let mut xs: [i32; N] = [0; N];
    let mut ys: [i32; N] = [0; N];
    for i in 0..n {
        xs[i] = scan.token();
        ys[i] = scan.token();
    }

    let mut tree = KTreeNode::new(4, R0, R1, R0, R1);
    for i in 0..n {
        tree.insert_point(xs[i], ys[i]);
    }
    for i in 0..n {
        let p = tree.nearest_empty(xs[i], ys[i]);
        writeln!(out, "{} {}", p.0, p.1).ok();
    }
}

#[derive(Clone, Debug)]
struct Range2Di32((i32, i32), (i32, i32));

impl Range2Di32 {
    pub fn has_point(&self, x: i32, y: i32) -> bool {
        let Self(xs, ys) = self;
        (x >= xs.0) && (x < xs.1) && (y >= ys.0) && (y < ys.1)
    }

    pub fn check(&self) -> bool {
        let Self(xs, ys) = self;
        xs.0 < xs.1 && ys.0 < ys.1
    }

    pub fn qua_son(&self, i: usize) -> Self {
        let Self(xs, ys) = self;
        let xmid = (xs.0 + xs.1) >> 1;
        let ymid = (ys.0 + ys.1) >> 1;
        let xs = if (i & 2) == 0 {(xs.0, xmid)} else {(xmid, xs.1)};
        let ys = if (i & 1) == 0 {(ys.0, ymid)} else {(ymid, ys.1)};
        Self(xs, ys)
    }

    pub fn mdis2point(&self, x: i32, y: i32) -> i32 {
        let Self(xs, ys) = self;

        let xd = if (x >= xs.0) && (x < xs.1) {
            0
        } else {
            (x - xs.0).abs().min((x - xs.1 + 1).abs())
        };
        let yd = if (y >= ys.0) && (y < ys.1) {
            0
        } else {
            (y - ys.0).abs().min((y - ys.1 + 1).abs())
        };

        xd + yd
    }

    pub fn mdis_nearest(&self, x: i32, y: i32) -> (i32, i32) {
        let Self(xs, ys) = self;

        let a = if (x >= xs.0) && (x < xs.1) {
            x
        } else if x < xs.0 {
            xs.0
        } else {
            xs.1 - 1
        };
        let b = if (y >= ys.0) && (y < ys.1) {
            y
        } else if y < ys.0 {
            ys.0
        } else {
            ys.1 - 1
        };

        (a, b)
    }

    pub fn is_point(&self) -> bool {
        let Self(xs, ys) = self;
        (xs.0 == xs.1 - 1) && (ys.0 == ys.1 - 1)
    }
}

#[derive(Clone)]
struct KTreeNode {
    r0: usize,
    son: Vec<Option<KTreeNode>>,

    range: Range2Di32,
    cnt: usize,
    cap: usize,
}

impl KTreeNode {
    pub fn new(r0: usize, xmin: i32, xmax: i32, ymin: i32, ymax: i32) -> Self {
        trace!("new node {} {} {} {}", xmin, xmax, ymin, ymax);
        Self {
            r0,
            son: std::iter::repeat(None).take(r0).collect(),
            range: Range2Di32((xmin, xmax), (ymin, ymax)),
            cnt: 0,
            cap: (((xmax - xmin) as usize) * (ymax - ymin) as usize),
        }
    }

    fn son_coord_range(&self, i: usize) -> Range2Di32 {
        self.range.qua_son(i)
    }

    fn son_new(&self, i: usize) -> Self {
        let Range2Di32(xs, ys) = self.son_coord_range(i);
        Self::new(self.r0, xs.0, xs.1, ys.0, ys.1)
    }

    fn son(&mut self, i: usize) -> &mut Self {
        if matches!(self.son[i], None) {
            self.son[i] = Some(self.son_new(i));
        }
        self.son[i].as_mut().unwrap()
    }
    
    fn is_leaf(&self) -> bool {
        self.range.is_point()
    }

    pub fn insert_point(&mut self, x: i32, y: i32) -> bool {
        if self.is_leaf() && self.range.has_point(x, y) {
            if 0 == self.cnt {
                self.cnt = 1;
                return true;
            } else {
                return false;
            }
        }
        for i in 0..4 {
            let range = self.son_coord_range(i);
            if range.has_point(x, y) {
                let r = self.son(i).insert_point(x, y);
                if r {
                    self.cnt += 1;
                }
                return r;
            }
        }
        false
    }

    pub fn nearest_empty(&self, x: i32, y: i32) -> (i32, i32) {
        trace!("nearest empty {} {}", x, y);
        self.do_nearest_empty(x, y, x.abs() + y.abs())
    }

    fn do_nearest_empty(&self, x: i32, y: i32, mut cut_q: i32) -> (i32, i32) {
        trace!("stat {}/{} {:?}", self.cnt, self.cap, self.range);
        if (self.cnt == self.cap) || (self.range.mdis2point(x, y) >= cut_q) {
            return (0, 0);
        }
        if self.is_leaf() {
            return (self.range.0.0, self.range.1.0);
        }
        let mut h: Vec<(i32, usize)> = (0..4).map(|i| (self.son_coord_range(i).mdis2point(x, y), i)).collect();
        h.sort();
        let mut r = (0, 0);
        for (_, i) in h {
            let p = if let Some(s) = self.son[i].as_ref() {
                s.do_nearest_empty(x, y, cut_q)
            } else {
                let rg = self.son_coord_range(i);
                if !rg.check() {
                    continue;
                }
                trace!("empty {}", i);
                rg.mdis_nearest(x, y)
            };
            let d = (x - p.0).abs() + (y - p.1).abs();
            if d < cut_q {
                cut_q = d;
                r = p;
                trace!("better ({}, {}) {} - {:?} {}", r.0, r.1, d, &self.range, i);
            }
        }
        r
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
