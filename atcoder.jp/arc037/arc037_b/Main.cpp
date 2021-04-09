/**
*    author:  shu8Cream
*    created: 09.04.2021 00:14:43
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vi used;
vector<bool> seen;
bool f;
void dfs(vvi to, int s, int c){
    for(auto v : to[s]){
        if(c==v) continue;
        if(seen[v]) f = false;
        else{
            seen[v]=true;
            dfs(to,v,s);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vvi to(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    int ans = 0;
    seen.assign(n, false);
    rep(i,n){
        if(!seen[i]){
            f = true;
            dfs(to,i,-1);
            if(f) ans++;
        }
    }
    cout << ans << endl;
}