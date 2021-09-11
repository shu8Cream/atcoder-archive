/**
*    author:  shu8Cream
*    created: 11.09.2021 20:40:30
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

bool check(vector<vector<char>> &a, vector<vector<char>> &b){
    int n = sz(a), m = sz(a[0]);
    if(n!=sz(b) || m!=sz(b[0])) return false;
    bool res = true;
    rep(i,n)rep(j,m){
        if(a[i][j]!=b[i][j]) res = false;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<char>> s(n,vector<char>(n)), t(n,vector<char>(n));
    rep(i,n)rep(j,n) cin >> s[i][j];
    rep(i,n)rep(j,n) cin >> t[i][j];
    int rs = 0, re = n-1, cs = 0, ce = n-1;  
    bool f = true;
    rep(i,n)rep(j,n){
        if(f && s[i][j]=='#'){
            rs = i;
            f = false;
        }
    }
    f = true;
    rrep(i,n)rep(j,n){
        if(f && s[i][j]=='#'){
            re = i;
            f = false;
        }
    }
    f = true;
    rep(i,n)rep(j,n){
        if(f && s[j][i]=='#'){
            cs = i;
            f = false;
        }
    }
    f = true;
    rrep(i,n)rep(j,n){
        if(f && s[j][i]=='#'){
            ce = i;
            f = false;
        }
    }
    vector<vector<char>> ss;
    for(int i=rs; i<=re; i++){
        vector<char> tmp;
        for (int j=cs; j<=ce; j++){
            tmp.push_back(s[i][j]);
        }
        ss.push_back(tmp);
    }

    rs = 0, re = n-1, cs = 0, ce = n-1;  
    f = true;
    rep(i,n)rep(j,n){
        if(f && t[i][j]=='#'){
            rs = i;
            f = false;
        }
    }
    f = true;
    rrep(i,n)rep(j,n){
        if(f && t[i][j]=='#'){
            re = i;
            f = false;
        }
    }
    f = true;
    rep(i,n)rep(j,n){
        if(f && t[j][i]=='#'){
            cs = i;
            f = false;
        }
    }
    f = true;
    rrep(i,n)rep(j,n){
        if(f && t[j][i]=='#'){
            ce = i;
            f = false;
        }
    }
    vector<vector<char>> tt;
    for(int i=rs; i<=re; i++){
        vector<char> tmp;
        for (int j=cs; j<=ce; j++){
            tmp.push_back(t[i][j]);
        }
        tt.push_back(tmp);
    }

    rep(k,4){
        if(check(ss,tt)){
            cout << "Yes" << endl;
            return 0;
        }
        int a = sz(ss[0]), b = sz(ss);
        vector<vector<char>> tmp(a, vector<char>(b));
        rep(i,b)rep(j,a){
            tmp[a-1-j][i] = ss[i][j];
        }
        ss = tmp;
    }
    cout << "No" << endl;
}