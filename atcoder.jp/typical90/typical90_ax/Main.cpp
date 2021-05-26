/**
*    author:  shu8Cream
*    created: 26.05.2021 11:21:58
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

const int mod = 1e9+7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,l;
    cin >> n >> l;
    vi dp(n+1);
    dp[0] = 1;
    rep(i,n){
        if(i+1<=n) (dp[i+1]+=dp[i])%=mod;
        if(i+l<=n) (dp[i+l]+=dp[i])%=mod;
    }
    cout << dp[n] << endl;
}