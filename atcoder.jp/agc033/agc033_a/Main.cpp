/**
*    author:  shu8Cream
*    created: 19.01.2021 21:05:56
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vi dx = {1,0,-1,0};
vi dy = {0,1,0,-1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];

    vvi dist(h,vi(w,-1));
    queue<P> q;
    rep(i,h)rep(j,w){
        if(a[i][j]=='#'){
            dist[i][j]=0;
            q.push({i,j});
        }
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        rep(i,4){
            int ni = v.first + dx[i];
            int nj = v.second + dy[i];
            if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
            if(dist[ni][nj]==-1){
                dist[ni][nj]=dist[v.first][v.second]+1;
                q.push({ni,nj});
            }
        }
    }

    int ans = 0;
    rep(i,h)rep(j,w){
        ans=max(ans,dist[i][j]);
    }
    cout << ans << endl;
}