/**
*    author:  shu8Cream
*    created: 06.01.2021 17:09:50
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vi to[2010];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x,y;
    cin >> n >> x >> y;
    x--; y--;
    rep(i,n-1){
        to[i].push_back(i+1);
        to[i+1].push_back(i);
    }
    to[x].push_back(y);
    to[y].push_back(x);

    vi cnt(n);

    rep(i,n){
        vi dist(n,-1);
        queue<int> que;
        dist[i] = 0;
        que.push(i);
        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (int nv : to[v]) {
                if (dist[nv] != -1) continue; 
                dist[nv] = dist[v] + 1;
                cnt[dist[nv]]++;
                que.push(nv);
            }
        }
    }
    rep(i,n-1) cout << cnt[i+1]/2 << endl;
}