/**
*    author:  shu8Cream
*    created: 04.09.2021 20:45:45
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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    set<string> s;
    s.insert("ABC");
    s.insert("ARC");
    s.insert("AGC");
    s.insert("AHC");
    s.erase(s1);
    s.erase(s2);
    s.erase(s3);
    for(auto p : s)cout << p << endl;
}