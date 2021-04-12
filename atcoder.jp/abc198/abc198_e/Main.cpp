/**
*    author:  shu8Cream
*    created: 11.04.2021 20:46:44
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vi c,ans,seen;
//vvi to;
map<int,int> color;

void dfs(vvi& to, int s){
    seen[s]=1;
    if(color[c[s]]==0) ans.push_back(s+1);
    color[c[s]]++;
    for(auto v : to[s]){
        if(seen[v]) continue;
        dfs(to,v);
    }
    color[c[s]]--;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    c.resize(n);
    seen.resize(n);
    rep(i,n) cin >> c[i];
    vvi to(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(to,0);
    sort(all(ans));
    rep(i,ans.size()) cout << ans[i] << endl;
}