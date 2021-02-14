/**
*    author:  shu8Cream
*    created: 15.02.2021 00:13:22
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
    int n;
    cin >> n;
    map<ll,int> m;
    rep(i,n){
        int a; cin >> a;
        m[a]++;
    }
    ll l=0, w=0;
    for(auto p : m){
        if(p.second>1){
            w=l;
            l=p.first;
        }
        if(p.second>3){
            l=p.first;
            w=l;
        }
    }
    ll ans = w*l;
    cout << ans << endl;
}