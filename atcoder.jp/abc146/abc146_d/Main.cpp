/**
*    author:  shu8Cream
*    created: 13.04.2021 20:50:02
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<P>;
using vvi = vector<vi>;

int color[100100];
void dfs(vvi &to, int s, int p, int pc){
    int c = 1;
    if(c==pc) c++;
    for(auto v : to[s]){
        if(v.first==p) continue;
        color[v.second] = c;
        dfs(to,v.first,s,c);
        c++;
        if(c==pc) c++;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vvi to(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back({b,i});
        to[b].push_back({a,i});
    }
    ll ans = 0, cur = 0;
    rep(i,n) ans=max(ans,(ll)to[i].size());
    cout << ans << endl;

    dfs(to,0,-1,-1);
    rep(i,n-1) cout << color[i] << endl;
}