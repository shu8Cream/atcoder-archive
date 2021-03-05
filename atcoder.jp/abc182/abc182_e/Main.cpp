/**
*    author:  shu8Cream
*    created: 05.03.2021 13:08:45
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int h,w,n,m;

const int MX = 1505;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

bool light[MX][MX];
bool wall[MX][MX];
bool ok[MX][MX];

bool visited[MX][MX];
bool memo[MX][MX];
bool f(int v, int i, int j){
    if(i<0 || i>=h || j<0 || j>=w) return false;
    if(wall[i][j]) return false;
    if(light[i][j]) return true;
    if(visited[i][j]) return memo[i][j];
    visited[i][j]=true;
    return memo[i][j] = f(v,i+di[v], j+dj[v]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> h >> w >> n >> m;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        a--; b--;
        light[a][b]=true;
    }
    rep(i,m){
        int c,d;
        cin >> c >> d;
        c--; d--;
        wall[c][d]=true;
    }
    rep(v,4){
        rep(i,h)rep(j,w) visited[i][j]=false;
        rep(i,h)rep(j,w) if(f(v,i,j)) ok[i][j]=true;
    }

    int ans = 0;
    rep(i,h)rep(j,w) if(ok[i][j]) ans++;
    cout << ans << endl;
}