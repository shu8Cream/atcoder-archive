/**
*    author:  shu8Cream
*    created: 23.02.2021 23:00:32
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
    int n,a,b,k;
    cin >> n >> a >> b >> k;
    vi p(k);
    rep(i,k) cin >> p[i];
    bool ok = true;
    set<int> s;
    s.insert(a);
    s.insert(b);
    rep(i,k){
        if(s.count(p[i])) ok=false;
        s.insert(p[i]);
    }
    cout << (ok ? "YES" : "NO") << endl;
}