/**
*    author:  shu8Cream
*    created: 16.05.2021 20:59:54
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; string s,t;
    cin >> n >> s >> t;
    vi a,b;
    rep(i,n) if(s[i]=='0') a.push_back(i);
    rep(i,n) if(t[i]=='0') b.push_back(i);
    if(a.size()!=b.size()){
        cout << -1 << endl;
        return 0;
    } 
    int ans = 0;
    rep(i,a.size()) if(a[i]!=b[i]) ans++;
    cout << ans << endl;
}