/**
*    author:  shu8Cream
*    created: 01.10.2021 15:37:38
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
const ll INF = 8e18;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
cout << H << " ";
debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int mod = 998244353;
struct mint{
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

mint fact[200200];
mint invfact[200200];

void init(){
    fact[0]=1;
    for(int i=1; i<200200; i++){
        fact[i]=fact[i-1]*i;
    }
    invfact[200200-1] = fact[200200-1].inv();
    for(int i=200200-2; i>=0; i--){
        invfact[i] = invfact[i+1]*(i+1);
    }
}

mint nCk(int n, int k){
    if(k<0 || n<k) return 0;
    return fact[n] * invfact[n-k] * invfact[k];
}

mint dp[420][420];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    init();

    int n,m; cin >> n >> m;
    n*=2;
    vvi p(n,vi(n));
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        p[a][b] = 1;
    }
    rep(i,n) dp[i][i] = 1;
    for(int w = 2; w<=n; w+=2){
        rep(l,n){
            int r = l+w;
            if(r>n) break;
            if(p[l][r-1]){
                dp[l][r] += dp[l+1][r-1];
            }
            for(int i=l+1; i<r; i++)if(p[i][r-1]){
                dp[l][r] += dp[l][i]*dp[i+1][r-1]*nCk((r-l)/2, (i-l)/2);
            }
        }
    }
    cout << dp[0][n] << endl;
}