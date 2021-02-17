/**
*    author:  shu8Cream
*    created: 17.02.2021 11:10:42
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vvi to(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    rep(i,n){
        vi dist(n,-1);
        queue<int> q;
        dist[i]=0;
        q.push(i);

        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int nv : to[v]){
                if(dist[nv]!=-1) continue;
                dist[nv]=dist[v]+1;
                q.push(nv);
            }
        }
        int ans=0;
        rep(j,n){
            if(dist[j]==2) ans++;
        }
        cout << ans << endl;
    }
}