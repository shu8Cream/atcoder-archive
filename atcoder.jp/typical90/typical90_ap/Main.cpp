/**
*    author:  shu8Cream
*    created: 19.05.2021 19:04:27
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
    int k; cin >> k;
    if(k%9!=0){
        cout << 0 << endl;
        return 0;
    }
    vi dp(k+1);
    dp[0] = 1;
    for(int i=1; i<=k; i++){
        for(int j=i; j>=i-9 && j>=0; j--){
            dp[i]+=dp[j];
            if(dp[i]>=mod) dp[i]-=mod;
        }
    }
    cout << dp[k] << endl;
}