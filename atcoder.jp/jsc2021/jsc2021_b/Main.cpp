/**
*    author:  shu8Cream
*    created: 17.04.2021 15:46:06
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    set<int> as,bs;
    rep(i,n){
        int a; cin >> a;
        as.insert(a);
    }
    rep(i,m){
        int b; cin >> b;
        bs.insert(b);
    }
    set<int> ans;
    for(auto p : as){
        if(!bs.count(p)) ans.insert(p);
    }
    for(auto p : bs){
        if(!as.count(p)) ans.insert(p);
    }
    for(auto p : ans) cout << p << endl;
}