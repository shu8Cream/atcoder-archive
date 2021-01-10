/**
*    author:  shu8Cream
*    created: 09.01.2021 20:57:22
**/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int deg[400400];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    dsu uf(400400);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
        uf.merge(a,b);
    }
    int ans = 0;
    for(auto g : uf.groups()){
        int e = 0;
        int v = g.size();
        for(auto node : g){
            e+=deg[node];
        }
        e/=2;
        ans+=min(e,v);
    }
    cout << ans << endl;
}