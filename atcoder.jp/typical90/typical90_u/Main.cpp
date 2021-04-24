/**
*    author:  shu8Cream
*    created: 23.04.2021 22:27:18
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int used[100100];
ll cnt = 0;

void dfs(vvi &to, vi &vs, int v){
    used[v] = 1;
    for(auto nv : to[v]){
        if(!used[nv]) dfs(to, vs, nv);
    }
    vs.push_back(v);
}

void rdfs(vvi &rto, int v){
    used[v] = 1;
    cnt++;
    for(auto nv : rto[v]){
        if(!used[nv]) rdfs(rto, nv);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vvi to(n), rto(n);
    vi vs(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        rto[b].push_back(a);
    }
    rep(i,n){
        if(!used[i]) dfs(to, vs, i);
    }
    ll ans = 0;
    reverse(all(vs));
    rep(i,n) used[i]=0;
    for(auto i : vs){
        if(used[i]) continue;
        cnt = 0;
        rdfs(rto,i);
        ans+=cnt*(cnt-1LL) / 2LL;
    }
    cout << ans << endl;
}