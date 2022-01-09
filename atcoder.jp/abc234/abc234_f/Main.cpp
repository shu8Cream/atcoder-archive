/**
*    author:  shu8Cream
*    created: 09.01.2022 15:08:54
**/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
// #define rep(i,n) for (int i=0; i<(n); i++)
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

template<class T>
struct FormalPowerSeries : vector<T> {
    using vector<T>::vector;
    using vector<T>::operator=;
    using F = FormalPowerSeries;

    F operator-() const {
        F res(*this);
        for (auto &e : res) e = -e;
        return res;
    }
    F &operator*=(const T &g) {
        for (auto &e : *this) e *= g;
        return *this;
    }
    F &operator/=(const T &g) {
        assert(g != T(0));
        *this *= g.inv();
        return *this;
    }
    F &operator+=(const F &g) {
        int n = (*this).size(), m = g.size();
        rep(i, min(n, m)) (*this)[i] += g[i];
        return *this;
    }
    F &operator-=(const F &g) {
        int n = (*this).size(), m = g.size();
        rep(i, min(n, m)) (*this)[i] -= g[i];
        return *this;
    }
    F &operator<<=(const int d) {
        int n = (*this).size();
        (*this).insert((*this).begin(), d, 0);
        (*this).resize(n);
        return *this;
    }
    F &operator>>=(const int d) {
        int n = (*this).size();
        (*this).erase((*this).begin(), (*this).begin() + min(n, d));
        (*this).resize(n);
        return *this;
    }
    F inv(int d = -1) const {
        int n = (*this).size();
        assert(n != 0 && (*this)[0] != 0);
        if (d == -1) d = n;
        assert(d > 0);
        F res{(*this)[0].inv()};
        while (res.size() < d) {
        int m = size(res);
        F f(begin(*this), begin(*this) + min(n, 2*m));
        F r(res);
        f.resize(2*m), internal::butterfly(f);
        r.resize(2*m), internal::butterfly(r);
        rep(i, 2*m) f[i] *= r[i];
        internal::butterfly_inv(f);
        f.erase(f.begin(), f.begin() + m);
        f.resize(2*m), internal::butterfly(f);
        rep(i, 2*m) f[i] *= r[i];
        internal::butterfly_inv(f);
        T iz = T(2*m).inv(); iz *= -iz;
        rep(i, m) f[i] *= iz;
        res.insert(res.end(), f.begin(), f.begin() + m);
        }
        return {res.begin(), res.begin() + d};
    }

    // fast: FMT-friendly modulus only
    F &operator*=(const F &g) {
      int n = (*this).size();
      *this = convolution(*this, g);
      (*this).resize(n);
      return *this;
    }
    F &operator/=(const F &g) {
      int n = (*this).size();
      *this = convolution(*this, g.inv(n));
      (*this).resize(n);
      return *this;
    }

    // // naive
    // F &operator*=(const F &g) {
    //   int n = (*this).size(), m = g.size();
    //   drep(i, n) {
    //     (*this)[i] *= g[0];
    //     rep2(j, 1, min(i+1, m)) (*this)[i] += (*this)[i-j] * g[j];
    //   }
    //   return *this;
    // }
    // F &operator/=(const F &g) {
    //   assert(g[0] != T(0));
    //   T ig0 = g[0].inv();
    //   int n = (*this).size(), m = g.size();
    //   rep(i, n) {
    //     rep2(j, 1, min(i+1, m)) (*this)[i] -= (*this)[i-j] * g[j];
    //     (*this)[i] *= ig0;
    //   }
    //   return *this;
    // }

    // sparse
    F &operator*=(vector<pair<int, T>> g) {
        int n = (*this).size();
        auto [d, c] = g.front();
        if (d == 0) g.erase(g.begin());
        else c = 0;
        drep(i, n) {
        (*this)[i] *= c;
        for (auto &[j, b] : g) {
            if (j > i) break;
            (*this)[i] += (*this)[i-j] * b;
        }
        }
        return *this;
    }
    F &operator/=(vector<pair<int, T>> g) {
        int n = (*this).size();
        auto [d, c] = g.front();
        assert(d == 0 && c != T(0));
        T ic = c.inv();
        g.erase(g.begin());
        rep(i, n) {
        for (auto &[j, b] : g) {
            if (j > i) break;
            (*this)[i] -= (*this)[i-j] * b;
        }
        (*this)[i] *= ic;
        }
        return *this;
    }

    // multiply and divide (1 + cz^d)
    void multiply(const int d, const T c) { 
        int n = (*this).size();
        if (c == T(1)) drep(i, n-d) (*this)[i+d] += (*this)[i];
        else if (c == T(-1)) drep(i, n-d) (*this)[i+d] -= (*this)[i];
        else drep(i, n-d) (*this)[i+d] += (*this)[i] * c;
    }
    void divide(const int d, const T c) {
        int n = (*this).size();
        if (c == T(1)) rep(i, n-d) (*this)[i+d] -= (*this)[i];
        else if (c == T(-1)) rep(i, n-d) (*this)[i+d] += (*this)[i];
        else rep(i, n-d) (*this)[i+d] -= (*this)[i] * c;
    }

    T eval(const T &a) const {
        T x(1), res(0);
        for (auto e : *this) res += e * x, x *= a;
        return res;
    }

    F operator*(const T &g) const { return F(*this) *= g; }
    F operator/(const T &g) const { return F(*this) /= g; }
    F operator+(const F &g) const { return F(*this) += g; }
    F operator-(const F &g) const { return F(*this) -= g; }
    F operator<<(const int d) const { return F(*this) <<= d; }
    F operator>>(const int d) const { return F(*this) >>= d; }
    F operator*(const F &g) const { return F(*this) *= g; }
    F operator/(const F &g) const { return F(*this) /= g; }
    F operator*(vector<pair<int, T>> g) const { return F(*this) *= g; }
    F operator/(vector<pair<int, T>> g) const { return F(*this) /= g; }
};

using mint = modint998244353;
using fps = FormalPowerSeries<mint>;
using sfps = vector<pair<int, mint>>;
mint fact[5050];


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    vi freq(26);
    rep(i,sz(s)) freq[s[i]-'a']++;
    fact[0] = 1;
    rep(i,5000) fact[i+1] = fact[i]*(i+1);
    fps cnv = {1};
    rep(i,5000) cnv.emplace_back(0);
    rep(i,26){
        fps a;
        rep(j,freq[i]+1){
            mint tmp = 1;
            tmp/=fact[j];
            a.push_back(tmp);
            // debug("---",char(i+'a'),j);
            // cout << tmp.val() << endl;
        }
        cnv*=a;
    }
    mint ans = 0;
    rep(i,sz(cnv)){
        // cout << cnv[i].val() << endl;
        ans+=cnv[i].val()*fact[i];
    }
    cout << ans.val()-1 << endl;
}