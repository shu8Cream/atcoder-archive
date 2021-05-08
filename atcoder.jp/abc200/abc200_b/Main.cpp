/**
*    author:  shu8Cream
*    created: 08.05.2021 20:43:31
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
    ll n,k;
    cin >> n >> k;
    rep(i,k){
        if(n%200==0) n/=200;
        else n = n*1000 + 200;
    }
    cout << n << endl;
}