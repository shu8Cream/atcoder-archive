/**
*    author:  shu8Cream
*    created: 21.05.2021 08:58:54
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
const int INF = 1001001001;
const vi dx = {1,0,-1,0};
const vi dy = {0,1,0,-1};

struct dircell {
    int r,c,dir;
};

int cost[1010][1010][4];
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w,rs,rt,cs,ct;
    cin >> h >> w >> rs >> cs >> rt >> ct;
    rs--; rt--; cs--; ct--;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    deque<dircell> q; 
    rep(i,h)rep(j,w)rep(k,4){
        cost[i][j][k]=INF;
    }
    rep(i,4){
        cost[rs][cs][i]=0;
        q.push_back({rs,cs,i});
    }
    while(!q.empty()){
        dircell u = q.front(); q.pop_front();
        rep(i,4){
            int nr = u.r + dx[i];
            int nc = u.c + dy[i];
            int tmp = cost[u.r][u.c][u.dir] + (u.dir!=i ? 1 : 0);
            if(nr<0 || nr>=h || nc<0 || nc>=w) continue;
            if(s[nr][nc]=='#') continue;
            if(cost[nr][nc][i]>tmp){
                cost[nr][nc][i]=tmp;
                if(u.dir==i) q.push_front({nr,nc,i});
                else q.push_back({nr,nc,i});
            }
        }
    }
    int ans = INF;
    rep(i,4) chmin(ans,cost[rt][ct][i]);
    cout << ans << endl;
}