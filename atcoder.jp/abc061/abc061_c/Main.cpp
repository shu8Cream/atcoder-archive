/**
*    author:  shu8Cream
*    created: 07.03.2021 21:00:04
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    vector<P> ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;
    sort(all(ab));
    ll tmp = 0;
    rep(i,n){
        tmp+=ab[i].second;
        if(tmp>=k){
            cout << ab[i].first << endl; 
            return 0;
        } 
    }
}