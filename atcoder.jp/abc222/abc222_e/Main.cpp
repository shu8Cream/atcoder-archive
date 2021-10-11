/**
*    author:  shu8Cream
*    created: 11.10.2021 22:19:20
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

bool dfs(int s, int t, int p, vector<vector<P>> &to, vi &cnt){
    if(s==t) return 1;
    for(auto [nxt,e] : to[s])if(nxt!=p){
        if(dfs(nxt,t,s,to,cnt)){
            cnt[e]++;
            return 1;
        }
    }
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    vi a(m); rep(i,m) cin >> a[i];
    rep(i,m) a[i]--;
    vector<vector<P>> to(n);
    rep(i,n-1){
        int u,v; cin >> u >> v;
        u--; v--;
        to[u].push_back({v,i});
        to[v].push_back({u,i});
    }

    vi cnt(n-1);
    rep(i,m-1) dfs(a[i],a[i+1],-1,to,cnt);

    int sum = 0;
    rep(i,n-1) sum+=cnt[i];
    if((sum+k)%2==1 || sum+k<0){
        cout << 0 << endl;
        return 0;
    }
    vector<mint> dp(100101);
    dp[0]=1;
    rep(i,n-1){
        for(int j=100100; j>=cnt[i]; j--){
            dp[j]+=dp[j-cnt[i]];
        }
    }
    cout << dp[(sum+k)/2] << endl;
}