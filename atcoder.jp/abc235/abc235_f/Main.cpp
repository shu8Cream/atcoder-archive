/**
*    author:  shu8Cream
*    created: 16.01.2022 13:56:52
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

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

template <class T> string to_string(T s);
template <class S, class T> string to_string(pair<S, T> p);
string to_string(char c) { return string(1, c); }
string to_string(string s) { return s; }
string to_string(const char s[]) { return string(s); }

template <class T>
string to_string(T v) {
    if (v.empty()) return "{}";
    string ret = "{";
    for (auto x : v) ret += to_string(x) + ",";
    ret.back() = '}';
    return ret;
}
template <class S, class T>
string to_string(pair<S, T> p) {
    return "{" + to_string(p.first) + ":" + to_string(p.second) + "}";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << to_string(H) << " ";
    debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

// i:i桁目までみて, j:cのうち何を使ったか, k:N以下かどうか
mint dp[10010][1<<10][2];
mint ds[10010][1<<10][2];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string N; ll m; cin >> N >> m;
    int n = sz(N);
    int cs = 0;
    rep(i,m){
        int c; cin >> c;
        cs |= 1<<c;
    }
    // 0: Nより小さい
    // 1: Nと同じ
    // 2: Nより大きい
    rep(i,n){
        int c = N[i]-'0';
        rep(bit,1<<10)rep(j,2){
            mint num = dp[i][bit][j];
            mint sum = ds[i][bit][j];
            rep(d,10){
                int new_bit = bit|(1<<d);
                int nj = j;
                if(j==1){
                    if(d>c) continue;
                    if(d<c) nj = 0;
                }
                dp[i+1][new_bit][nj] += num;
                ds[i+1][new_bit][nj] += sum*10+num*d;
                if(bit==0 && (i==0?1:0)==j && d!=0){
                    dp[i+1][new_bit][nj] += 1;
                    ds[i+1][new_bit][nj] += d;
                }
            }
        }
    }
    mint ans = 0;
    rep(bit,1<<10){
        if(cs!=(cs&bit)) continue;
        bitset<8> bs(bit);
        // cerr << bs << endl;
        // cerr << ds[n][bit][0] << " " << ds[n][bit][1] << endl;
        ans+=ds[n][bit][0]+ds[n][bit][1];
    }
    cout << ans << endl;
}