/**
*    author:  shu8Cream
*    created: 18.11.2021 18:48:34
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
    int n,c;
    cin >> n >> c;
    vvi table(32, vi(300000));
    rep(i,n){
        int s,t,a; cin >> s >> t >> a;
        s--;
        table[a][s]++;
        table[a][t]--;
    }

    rep(i,c+1)rep(j,200000){
        table[i][j+1] += table[i][j];
    }
    rep(i,c+1)rep(j,200000){
        if(table[i][j]>0) table[i][j] = 1;
    }
    ll ans = 0;
    rep(i,200000){
        ll cnt = 0;
        rep(j,c+1) cnt+=table[j][i];
        chmax(ans,cnt);
    }
    cout << ans << endl;
}