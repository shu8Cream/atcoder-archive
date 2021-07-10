/**
*    author:  shu8Cream
*    created: 07.07.2021 00:30:44
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

const vi dx = {1,0,-1,0};
const vi dy = {0,1,0,-1};

int h,w;

int used[20][20];

// s->now, b->start
ll dfs(vector<string> &c, P s, P b){
    ll x,y; tie(x,y) = s;
    ll sx,sy; tie(sx,sy) = b;
    if(x==sx && y==sy && used[x][y]) return 0;
    used[x][y] = 1;
    ll res = -100000;
    rep(i,4){
        ll nx = x + dx[i], ny = y + dy[i];
        if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
        if(c[nx][ny]=='#') continue;
        if((nx!=sx || ny!=sy) && used[nx][ny]) continue;
        ll v = dfs(c,{nx,ny},b);
        chmax(res,v+1);
    }
    used[x][y] = 0;
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    ll ans = 0;
    rep(i,h)rep(j,w){
        chmax(ans, dfs(c,{i,j},{i,j}));
    }
    if(ans<=2) ans = -1;
    cout << ans << endl;
}