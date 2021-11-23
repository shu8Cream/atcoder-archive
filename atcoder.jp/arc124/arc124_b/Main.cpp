/**
*    author:  shu8Cream
*    created: 22.11.2021 15:12:50
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    sort(all(b));
    sort(all(a));
    vi c(n);
    rep(i,n) c[i] = (a[0]^b[i]);
    vi ans;
    vi d(n);
    rep(i,n){
        rep(j,n) d[j] = c[i]^a[j];
        sort(all(d));
        if(b==d) ans.push_back(c[i]);
    }
    sort(all(ans));
    ans.erase(unique(all(ans)),ans.end());
    cout << sz(ans) << endl;
    for(auto p : ans) cout << p << endl;
}