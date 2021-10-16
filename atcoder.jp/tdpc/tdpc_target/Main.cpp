/**
*    author:  shu8Cream
*    created: 16.10.2021 13:52:17
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

int LIS(vector<P> &a){
    int n = sz(a);
    vi dp(n,INF);
    rep(i,n){
        auto itr = lower_bound(all(dp), -a[i].second);
        *itr = -a[i].second;
    }
    return lower_bound(all(dp), INF) - dp.begin();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<P> target(n);
    rep(i,n){
        int x,r; cin >> x >> r;
        target[i] = {x-r,x+r};
    }
    sort(all(target));
    cout << LIS(target) << endl;
}