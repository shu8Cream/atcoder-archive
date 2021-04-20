/**
*    author:  shu8Cream
*    created: 01.04.2021 20:20:00
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vector<pair<int, int> > g[100000];

pair<int, int> tddfs(int v, int par = -1) {
    pair<int, int> ret = {0, v};
    for (auto &x : g[v]) {
        int w, cost;
        tie(w, cost) = x;
        if (w == par) continue;
        auto r = tddfs(w, v);
        ret = max(ret,  {cost+r.first, r.second});
    }
    return ret;
}

int treeDiameter() {
    auto v = tddfs(0);
    auto w = tddfs(v.second);
    return w.first;
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
        g[a].push_back({b,1});
        g[b].push_back({a,1});
    }
    cout << treeDiameter()+1 << endl;
}