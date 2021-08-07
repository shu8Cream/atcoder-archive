/**
*    author:  shu8Cream
*    created: 07.08.2021 12:15:44
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
using vs = vector<string>;
using vvs = vector<vs>;

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
    int n,m; cin >> n >> m;
    vs s(m);
    rep(i,m) cin >> s[i];

    vs ans(n);
    rep(i,n) ans[i]="";
    int cnt = 0;
    int cnt2 = 0;

    while(cnt<n){
        if(n-ans[cnt].size() >= s[cnt2].size()){
            ans[cnt]+=s[cnt2++];
        }else{
            ans[cnt]+=string(n-ans[cnt].size(), '.');
            cnt++;
        }
    }

    rep(i,n) cout << ans[i] << endl;
}