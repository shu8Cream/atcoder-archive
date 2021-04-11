/**
*    author:  shu8Cream
*    created: 11.04.2021 10:41:09
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<P> c(m);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        c[i]={b,a};
    }
    sort(all(c));
    int ans = 0, cur = -1;
    rep(i,m){
        int a,b; tie(b,a) = c[i];
        if(cur<=a || b<cur){
            cur = b;
            ans++;
        }
    }
    cout << ans << endl;
}