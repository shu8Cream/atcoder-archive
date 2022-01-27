use proconio::*;

fn main() {
    input! {
        n: usize,
        m: usize,
        s: [String;n],
        t: [String;m],
    }
    let mut ans = vec![0;n];
    let mut cur = 0;
    for i in 0..n {
        if s[i] == t[cur] {
            ans[i] = 1;
            cur+=1;
        }
    }
    for x in ans {
        println!("{}", if x == 1 {"Yes"} else {"No"});
    }
}
