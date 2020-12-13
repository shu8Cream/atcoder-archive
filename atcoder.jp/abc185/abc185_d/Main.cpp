/**
*    author:  shu8Cream
*    created: 13.12.2020 21:38:24
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    int n,m;
    cin >> n >> m;
    vi a(m);
    rep(i,m) cin >> a[i];
    a.push_back(0);
    a.push_back(n+1);
    sort(a.begin(), a.end());
    int k=n;
    vi akimas;
    rep(i,m+1){
        if(a[i+1]-a[i]-1==0) continue;
        k=min(k,a[i+1]-a[i]-1);
        akimas.push_back(a[i+1]-a[i]-1);
    }
    int ans = 0;
    rep(i,akimas.size()){
        ans+=(akimas[i]+k-1)/k;
    }
    //cout << k << endl;
    //rep(i,akimas.size()) cout << akimas[i] << endl;
    cout << ans << endl;
}