/**
*    author:  shu8Cream
*    created: 13.05.2021 20:43:32
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
    ll n; cin >> n;
    vvi to(n);
    vi A(n),B(n);
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
        A[i] = a;
        B[i] = b;
    }
    vi dp(n);
    function<void(int,int)> dfs = [&](int pos, int p){
        dp[pos] = 1;
        for(auto i : to[pos]){
            if(i!=p){
                dfs(i,pos);
                dp[pos]+=dp[i];
            }
        }
    };
    dfs(0,-1);
    ll ans = 0;
    rep(i,n-1){
        ll t = min(dp[A[i]],dp[B[i]]);
        ans += t * (n-t);
    }
    cout << ans << endl;
}