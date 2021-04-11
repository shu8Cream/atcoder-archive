/**
*    author:  shu8Cream
*    created: 11.04.2021 20:46:09
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
    string s,t; cin >> s;
    reverse(all(s));
    t=s;
    int n = s.size();
    bool ok = false;
    rep(i,10){
        string tt = t;
        reverse(all(tt));
        if(t==tt) ok = true;
        t+="0";
    }
    cout << (ok ? "Yes" : "No") << endl;
}