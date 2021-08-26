#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) x.begin(), x.end()
using ll = long long; 
using vi = vector<ll>;
using vvi = vector<vi>;

const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint dp[220000];
mint sdp[220000];

int main(void){
    int n,k; cin >> n >> k;
    vi L(k),R(k);
    rep(i,k) cin >> L[i] >> R[i];

    dp[1] = 1; sdp[1]=1;
    for(int i=2; i<=n; i++){
        rep(j,k){
            int l = max(i-R[j], 1LL);
            int r = i-L[j];
            if (r < 0) continue;
            dp[i] += sdp[r] - sdp[l-1];
        }
        sdp[i] = sdp[i-1] + dp[i];
    }
    
    cout << dp[n] << endl;
}
