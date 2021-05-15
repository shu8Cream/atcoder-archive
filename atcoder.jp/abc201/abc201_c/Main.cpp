/**
*    author:  shu8Cream
*    created: 15.05.2021 20:32:47
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    ll n = s.size();
    ll maru = 0, batsu = 0, hate = 0;
    rep(i,n){
        if(s[i]=='o') maru++;
        if(s[i]=='x') batsu++;
        if(s[i]=='?') hate++;
    }
    ll ans = 0;
    rep(i,10)rep(j,10)rep(k,10)rep(l,10){
        string t = "xxxxxxxxxx";
        t[i] = 'o';
        t[j] = 'o';
        t[k] = 'o';
        t[l] = 'o';
        bool f = true;
        rep(_,10){
            if(s[_]=='x' && t[_]=='o') f = false;
            if(s[_]=='o' && t[_]=='x') f = false;
        }
        if(f) ans++;
    }
    cout << ans << endl;
}