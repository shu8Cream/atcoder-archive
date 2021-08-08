/**
*    author:  shu8Cream
*    created: 08.08.2021 12:43:01
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

const int mod = 998244353;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w; cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    ll ans = 1;
    int len = h+w-1;
    vvi cnt(len, vi(3));
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='R') cnt[i+j][0]++;
            if(s[i][j]=='B') cnt[i+j][1]++;
            if(s[i][j]=='.') cnt[i+j][2]++;
        }
    }
    rep(i,len){
        int limit = min({i+1, len-i, min(h,w)});
        if(cnt[i][2]==limit)
            (ans*=2)%=mod;
        else if(cnt[i][0]>0 && cnt[i][1]>0)
            ans=0;
    }

    cout << ans << endl;
}