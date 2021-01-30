/**
*    author:  shu8Cream
*    created: 30.01.2021 20:42:01
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
    ll n,s,d;
    cin >> n >> s >> d;
    vector<ll> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    rep(i,n){
        if(x[i]<s && y[i]>d){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}