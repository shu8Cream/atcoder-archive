/**
*    author:  shu8Cream
*    created: 24.04.2021 20:47:16
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
    int a,b,c;
    cin >> a >> b >> c;
    cout << (a*a+b*b<c*c ? "Yes" : "No") << endl;
}