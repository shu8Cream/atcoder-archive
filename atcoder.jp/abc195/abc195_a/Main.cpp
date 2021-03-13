/**
*    author:  shu8Cream
*    created: 13.03.2021 20:32:00
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
    int m,h;
    cin >> m >> h;
    bool ok = false;
    if(h%m==0) ok =true;
    cout << (ok ? "Yes" : "No") << endl;
}