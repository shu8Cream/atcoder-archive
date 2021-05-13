/**
*    author:  shu8Cream
*    created: 12.05.2021 09:06:11
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
    ll a,b; cin >> a >> b;
    if(b/gcd(a,b)>1000000000000000000/a){
        cout << "Large" << endl;
        return 0;
    }
    cout << a/gcd(a,b)*b << endl;
}