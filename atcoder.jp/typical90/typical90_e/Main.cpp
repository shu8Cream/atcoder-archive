/**
*    author:  shu8Cream
*    created: 04.04.2021 13:25:31
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<ll>;
using vvi = vector<vi>;

const int mod = 1000000007;

ll mod_pow(ll a, ll b, ll n){
    if(b==0) return 1;
    if(b%2!=0) return a * mod_pow(a, b-1, n) % n;
    else return mod_pow(a * a % n, b / 2, n) % n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,b,k;
    cin >> n >> b >> k;
    vi c(k); rep(i,k) cin >> c[i];

    vi pow2(64);
    rep(i,63) pow2[i]=mod_pow(10LL,(1LL<<i),b);

    vvi dp(64,vi(1005));
    rep(i,k) dp[0][c[i]%b]++;
    
    rep(i,62)rep(j,b){
        rep(l,b){
            int nex = (j*pow2[i]+l)%b;
            dp[i+1][nex]+=dp[i][j]*dp[i][l];
            dp[i+1][nex]%=mod;
        }
    }

    vvi ans(64,vi(1005));
    ans[0][0]=1;
    rep(i,62){
        if((n&(1LL<<i))!=0LL){
            rep(j,b)rep(l,b){
                int nex = (j*pow2[i]+l)%b;
                ans[i+1][nex]+=ans[i][j]*dp[i][l];
                ans[i+1][nex]%=mod;
            }
        }else{
            rep(j,b) ans[i+1][j]=ans[i][j];
        }
    }
    cout << ans[62][0] << endl;
}