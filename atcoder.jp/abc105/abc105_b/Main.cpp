/**
*    author:  shu8Cream
*    created: 24.04.2021 20:26:43
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
    int n;
    cin >> n;
    bool ok = false;
    rep(i,100)rep(j,100){
        if(i*4+j*7==n) ok = true;
    }
    cout << (ok ? "Yes" : "No") << endl;
}