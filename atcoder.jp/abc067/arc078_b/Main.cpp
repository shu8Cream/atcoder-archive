/**
*    author:  shu8Cream
*    created: 17.03.2021 00:48:01
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int INF = 1001001001;

void bfs(vvi to, vi& d, int s){
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty()){
        int nv = q.front();
        q.pop();
        for(auto p : to[nv]){
            if(d[p]!=INF) continue;
            d[p]=min(d[p],d[nv]+1);
            q.push(p);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vvi to(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vi fennec(n,INF);
    vi snuke(n,INF);
    bfs(to, fennec, 0);
    bfs(to, snuke, n-1);
    int cnt=0;
    rep(i,n){
        if(fennec[i]<=snuke[i]) cnt++;
        else cnt--;
    }
    cout << ((cnt>0) ? "Fennec" : "Snuke") << endl;
}