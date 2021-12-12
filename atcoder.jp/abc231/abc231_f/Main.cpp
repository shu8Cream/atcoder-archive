/**
*    author:  shu8Cream
*    created: 11.12.2021 21:26:17",
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

template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + ":" + to_string(p.second) + "}";
}
template <class T>
string to_string(T v) {
  if (v.empty()) return "{}";
  string ret = "{";
  for (auto x : v) ret += to_string(x) + ",";
  ret.back() = '}';
  return ret;
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

template <typename T>
vector<T> compress(vector<T> &a){
    auto b = a;
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    for(auto &p:a) p = lower_bound(all(b),p) - b.begin();
    return a;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi A(n),B(n);
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];
    vi a = compress(A);
    vi b = compress(B);
    vector<P> present(n);
    rep(i,n) present[i] = {a[i],-b[i]};
    sort(all(present));
    debug(present);
    BIT<ll> bit(n);
    ll ans = n;
    map<P,ll> mp;
    rep(i,n){
        auto[pa,pb] = present[i]; pb*=-1;
        mp[present[i]]=bit.sum(n-1)-bit.sum(pb-1);
        bit.add(pb,1);
    }
    rep(i,n){
        ans += mp[present[i]];
    }
    cout << ans << endl;
}