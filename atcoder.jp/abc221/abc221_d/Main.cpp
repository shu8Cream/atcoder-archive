/**
*    author:  shu8Cream
*    created: 02.10.2021 20:31:58
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vi c(2*n);
    rep(i,n){
        c[i*2] = a[i];
        c[i*2+1] = a[i]+b[i];
    }
    auto cmp = compress(c);
    vi table(400400);
    ll last = 0;
    rep(i,n){
        table[cmp[i*2]]++;
        table[cmp[i*2+1]]--;
        chmax(last,cmp[i*2]);
        chmax(last,cmp[i*2+1]);
    }
    rep(i,400400){
        if(0<i) table[i] += table[i-1];
    }

    // rep(i,last) cout << table[i] << endl;

    vi ans(n+1);
    map<ll,ll> tocmp,toori;
    rep(i,2*n) tocmp[c[i]] = cmp[i];
    rep(i,2*n) toori[cmp[i]] = c[i];

    rep(i,last){
        ans[table[i]] += toori[i+1]-toori[i];
    }

    rep(i,n) cout << ans[i+1] << " ";
    cout << endl;
}