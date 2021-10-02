/**
*    author:  shu8Cream
*    created: 02.10.2021 21:46:26
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

template <typename T>
vector<T> compress(vector<T> a){
    vector<T> b;
    set<T> s;
    int n = a.size();
    rep(i,n) s.insert(a[i]);
    map<T,T> m;
    int i=0;
    for(auto p : s){
        m[p]=i;
        i++;
    }
    rep(i,n) b.push_back(m[a[i]]);
    return b;
}

void naive(int n, vi &a){
    mint res = 0;
    rep(i,n)for(int j=i+1; j<n; j++){
        if(a[i]>a[j]) continue;
        res += mint(2).pow(j-i-1);
    }
    cout << res << endl;
}

template<typename T>
struct BIT{
public:
    int n; vector<T> a;
    BIT(int n_):n(n_),a(n+1,0){}

    void add(int idx, T x){
        idx++;
        if(idx<=0 || n<idx){ cerr << "Index error" << endl; return; }
        for(int i=idx; i<=n; i+=i&(-i)){
            a[i]+=x;
        }
    }

    T sum(int idx){
        T res = 0;
        idx++;
        if(idx<0 || n<idx){ cerr << "Index error" << endl; return 0; }
        if(idx==0) return 0;
        for(int i=idx; i>0; i-=(i&-i)){
            res+=a[i];
        }
        return res;
    }

    T sum(int l, int r){
        if(l==0) return sum(r-1);
        return sum(r-1)-sum(l-1);
    }
};


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    mint ans = 0;
    vi cmp = compress(a);
    BIT<mint> bit(n);
    rep(i,n){
        ans += bit.sum(cmp[i]) * mint(2).pow(i);
        bit.add(cmp[i],mint(2).pow(i+1).inv());
    }
    cout << ans << endl;
}