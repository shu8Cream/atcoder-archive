/**
*    author:  shu8Cream
*    created: 26.01.2021 10:41:14
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const vi dx = {1,0,-1,0};
const vi dy = {0,1,0,-1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;

    rep(ii,h)rep(jj,w){
        vvi dist(h,vi(w,-1));
        queue<P> q;
        if(s[ii][jj]=='#') continue;
        dist[ii][jj]=0;
        q.push({ii,jj});

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            rep(k,4){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
                if(s[ni][nj]=='#') continue;
                if(dist[ni][nj]!=-1) continue;
                dist[ni][nj]=dist[i][j]+1;
                q.push({ni,nj});
            }
        }
        rep(i,h)rep(j,w) ans=max(ans,dist[i][j]);
    }
    cout << ans << endl;
}