/**
*    author:  shu8Cream
*    created: 16.10.2021 00:13:45
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

int dp[110][110][110];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    rep(i,n){
        int a,b,c,w; cin >> a >> b >> c >> w;
        dp[a][b][c] = max(dp[a][b][c], w);
    }
    rep(i,101)rep(j,101)rep(k,101){
        chmax(dp[i+1][j][k], dp[i][j][k]);
        chmax(dp[i][j+1][k], dp[i][j][k]);
        chmax(dp[i][j][k+1], dp[i][j][k]);
    }
    rep(i,m){
        int x,y,z; cin >> x >> y >> z;
        cout << dp[x][y][z] << endl;
    }
}