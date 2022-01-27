use proconio::*;

fn main() {
    input! {
        n: usize,
        a: [u32;4*n-1],
    }
    let mut ans = 0;
    for p in a {
        ans^=p;
    }
    println!("{}", ans);
}
