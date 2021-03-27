/**
*    author:  shu8Cream
*    created: 27.03.2021 17:57:21
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
    ll n,m;
    string s,t;
    cin >> n >> m >> s >> t;
    ll x = lcm(n,m), g = gcd(n,m);
    if(m>n){
        swap(n,m);
        swap(s,t);
    }
    rep(i,g){
        if(s[x/m*i]!=t[x/n*i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << x << endl;
}