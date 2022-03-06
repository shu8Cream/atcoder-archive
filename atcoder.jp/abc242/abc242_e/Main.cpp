/**
*    author:  shu8Cream
*    created: 05.03.2022 21:36:12
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

const int mod = 998244353;
struct mint{
    ll x;
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

    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}

    bool operator==(const mint &other) const {
        return x == other.x;
    }
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}


ll mod_pow(ll a, ll b, ll n){
    if(b==0) return 1;
    if(b%2!=0) return a * mod_pow(a, b-1, n) % n;
    else return mod_pow(a * a % n, b / 2, n) % n;
}

void solve(){
    int n; string s; cin >> n >> s;
    ll half = (n+1)/2;
    mint ans = 0;
    mint t = 26;
    rep(i,half){
        ll c = s[i] -'A';
        ans += t.pow(half-(i+1))*c;
    }
    string rs = s.substr(0,(n+1)/2);
    string fs = rs;
    reverse(all(rs));
    string cmp;
    if(n%2){
        cmp = fs.substr(0,sz(fs)-1) + rs;
        // cerr << cmp << " " << s << endl;
    }else{
        cmp = fs + rs;
        // cerr << cmp << " " << s << endl;
    }
    if(cmp<=s) ans = ans + 1;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
}