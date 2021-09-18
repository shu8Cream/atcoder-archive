/**
*    author:  shu8Cream
*    created: 18.09.2021 20:48:15
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
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
    string x; int n;
    cin >> x >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    map<char,char> m1,m2;
    rep(i,sz(x)){
        m1[(char)('a'+i)] = x[i];
        m2[x[i]] = (char)('a'+i);
    }
    rep(i,n)rep(j,sz(s[i])){
        s[i][j] = m2[s[i][j]];
    }
    sort(all(s));
    rep(i,n)rep(j,sz(s[i])){
        s[i][j] = m1[s[i][j]];
    }
    rep(i,n) cout << s[i] << endl;
}