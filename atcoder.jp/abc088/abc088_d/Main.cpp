/**
*    author:  shu8Cream
*    created: 18.12.2020 12:47:48
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vvi dist(h, vi(w,-1));
    dist[0][0]=1;
    queue<P> q;
    q.push({0,0});

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        rep(k,4){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
            if(s[ni][nj]=='#') continue;
            if(dist[ni][nj]!=-1) continue;
            dist[ni][nj]=dist[i][j]+1;
            q.push({ni,nj});
        }
    }

    set<int> se;
    int ans=0;
    rep(i,h)rep(j,w){
        if(s[i][j]=='#' && dist[i][j]==-1) continue;
        else if(dist[i][j]==-1) { ans++; continue; }
        if(dist[h-1][w-1]<dist[i][j]) { ans++; continue; }
        if(se.count(dist[i][j])) ans++;
        se.insert(dist[i][j]);
    }

    if(dist[h-1][w-1]!=-1) cout << ans << endl;
    else cout << -1 << endl;
}