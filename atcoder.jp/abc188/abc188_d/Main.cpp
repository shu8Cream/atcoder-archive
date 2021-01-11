/**
*    author:  shu8Cream
*    created: 10.01.2021 20:38:10
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
    ll n,C;
    cin >> n >> C;
    map<ll,ll> abc;
    rep(i,n){
        ll a,b,c;
        cin >> a >> b >> c;
        abc[a]+=c;
        abc[b+1]-=c;
    }
    ll pf=0;
    for(auto p : abc){
        if(pf!=0) abc[p.first]=abc[p.first]+abc[pf];
        pf = p.first;
    }
    for(auto p : abc){
        if(p.second>C) abc[p.first]=C;
    }
    ll ans = 0, ps = 0;
    pf = 0;
    for(auto p : abc){
        if(pf!=0) ans+=(p.first-pf)*ps;
        pf=p.first;
        ps=p.second;
    }
    cout << ans << endl;
}