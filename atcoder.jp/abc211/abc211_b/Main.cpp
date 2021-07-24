/**
*    author:  shu8Cream
*    created: 24.07.2021 20:10:52
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
    vector<string> s(4);
    rep(i,4) cin >> s[i];
    set<string> se;
    se.insert("H");
    se.insert("2B");
    se.insert("3B");
    se.insert("HR");
    for(auto p : s){
        if(se.count(p)) se.erase(p);
    }
    cout << (se.empty() ? "Yes" : "No") << endl;
}