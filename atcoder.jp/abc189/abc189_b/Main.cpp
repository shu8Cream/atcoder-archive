/**
*    author:  shu8Cream
*    created: 23.01.2021 20:46:46
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
    int n,x;
    cin >> n >> x;
    vector<ll> v(n),p(n);
    rep(i,n) cin >> v[i] >> p[i];
    ll ans = 0;
    rep(i,n){
        ans+=v[i]*p[i];
        if(ans>x*100){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}