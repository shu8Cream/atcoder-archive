/**
*    author:  shu8Cream
*    created: 02.05.2021 10:38:11
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int n;

bool check(ll mid, vvi &a){
    set<int> s;
    rep(i,n){
        int b = 0;
        for(ll &j : a[i]){
            b <<= 1;
            b |= j >= mid;
        }
        s.insert(b);
    }
    for(int x : s)for(int y : s)for(int z : s){
        if((x|y|z)==31) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    vvi a(n,vi(5));
    rep(i,n)rep(j,5) cin >> a[i][j];
    ll ok = 0, ng = 1001001001;
    while(ng-ok>1){
        ll mid = (ng + ok) / 2;
        if(check(mid,a)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}