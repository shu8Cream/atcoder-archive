/**
*    author:  shu8Cream
*    created: 26.01.2021 00:30:28
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
    vi a(m),b(m);
    set<int> s;
    rep(i,m){
        cin >> a[i] >> b[i];
        if(a[i]==1) s.insert(b[i]);
    }
    bool f = false;
    rep(i,m) if(s.count(a[i]) && b[i]==n) f = true;
    cout << (f ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}