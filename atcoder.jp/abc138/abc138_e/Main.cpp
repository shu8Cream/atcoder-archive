/**
*    author:  shu8Cream
*    created: 28.08.2021 14:07:41
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
    string s,t; cin >> s >> t;
    vvi to(26);
    int n = sz(s);
    rep(i,n) to[s[i]-'a'].push_back(i+1);

    int len = sz(t);
    rep(i,len){
        if(to[t[i]-'a'].empty()){
            cout << -1 << endl;
            return 0;
        }
    }

    vi a(len);
    rep(i,len){
        int x = t[i]-'a';
        if(!i){
            a[i] = to[x][0];
            continue;
        }
        int itr = upper_bound(all(to[x]), a[i-1]) - to[x].begin();
        if(itr==sz(to[x])) a[i] = to[x][0];
        else{
            a[i] = to[x][itr];
        }
    }
    ll ans = 0;
    a.push_back(0);
    rep(i,len){
        if(a[i]>=a[i+1] && i==len-1) ans += a[len-1];
        else if(a[i]>=a[i+1]) ans += n;
    }
    cout << ans << endl;
}