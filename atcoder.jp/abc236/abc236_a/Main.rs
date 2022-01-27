use proconio::*;
use proconio::marker::*;
use itertools::*;

fn main() {
    input! {
        mut s: Chars,
        a: Usize1,
        b: Usize1,
    }
    s.swap(a,b);
    println!("{}", s.iter().join(""));
}
