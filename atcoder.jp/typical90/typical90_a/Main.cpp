/**
*    author:  shu8Cream
*    created: 30.03.2021 10:17:26
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<ll>;
using vvi = vector<vi>;

int n,l,k;
vi a;

bool check(int dist){
    int last = 0;
    rep(i,k+1){
        int cur = last + 1;
        while(cur<n+2 && a[cur]-a[last]<dist) cur++;
        if(cur==n+2) return false;
        last = cur;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> l >> k;
    a.resize(n+2);
    rep(i,n) cin >> a[i+1];
    a[n+1]=l;
    ll ng = 1e9, ok = -1;
    while(ng-ok>1){
        ll mid = (ng + ok) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}