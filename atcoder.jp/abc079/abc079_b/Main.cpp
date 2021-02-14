/**
*    author:  shu8Cream
*    created: 15.02.2021 00:08:01
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
    int n;
    cin >> n;
    vector<ll> l(n+1);
    l[0]=2; l[1]=1;
    rep(i,n) l[i+2]=l[i+1]+l[i];
    cout << l[n] << endl;
}