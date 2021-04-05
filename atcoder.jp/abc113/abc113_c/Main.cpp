/**
*    author:  shu8Cream
*    created: 05.04.2021 22:18:07
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
    vector<P> in(m);
    vvi to(n+1);
    rep(i,m){
        int p,y; cin >> p >> y;
        to[p].push_back(y);
        in[i]={p,y};
    }
    rep(i,n) sort(all(to[i+1]));
    for(auto [p,y] : in){
        int x = lower_bound(all(to[p]),y) - to[p].begin()+1;
        printf("%06d%06d\n",p,x);
    }
}