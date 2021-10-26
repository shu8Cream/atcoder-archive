/**
*    author:  shu8Cream
*    created: 23.10.2021 20:55:02
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

ll dp[200200];
ll rmx[200200];
ll cmx[200200];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w,n; cin >> h >> w >> n;
    vi r(n),c(n),a(n);
    map<ll,vi> m;
    rep(i,n){
        cin >> r[i] >> c[i] >> a[i];
        m[-a[i]].push_back(i);
    }
    for(auto[val,vec] : m){
        for(auto idx : vec){
            dp[idx] = max(rmx[r[idx]], cmx[c[idx]]);
        }
        for(auto idx : vec){
            rmx[r[idx]] = max(rmx[r[idx]], dp[idx]+1);
            cmx[c[idx]] = max(cmx[c[idx]], dp[idx]+1);
        }
    }
    rep(i,n) cout << dp[i] << (i==n-1 ? "\n" : " ");
}