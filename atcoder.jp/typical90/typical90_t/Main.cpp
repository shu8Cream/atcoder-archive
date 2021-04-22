/**
*    author:  shu8Cream
*    created: 21.04.2021 22:18:49
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

ll mypow(ll a, ll b){
    if(b==0) return 1;
    if(b%2!=0) return a * mypow(a, b-1);
    else return mypow(a * a, b / 2);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b,c;
    cin >> a >> b >> c;
    cout << (a<mypow(c,b) ? "Yes" : "No") << endl;
}