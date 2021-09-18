/**
*    author:  shu8Cream
*    created: 18.09.2021 20:48:05
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
    string s1,s2,s3,t;
    cin >> s1 >> s2 >> s3 >> t;
    string ans = "";
    rep(i,sz(t)){
        if(t[i]=='1') ans += s1;
        if(t[i]=='2') ans += s2;
        if(t[i]=='3') ans += s3;
    }
    cout << ans << endl;
}