/**
*    author:  shu8Cream
*    created: 13.05.2021 21:37:52
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    vi b;
    rep(i,n){
        auto itr = lower_bound(rall(b),a[i]);
        if(itr==b.rbegin()) b.push_back(a[i]);
        else {itr--; *itr=a[i];}
    }
    cout << b.size() << endl;
}