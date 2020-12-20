/**
*    author:  shu8Cream
*    created: 20.12.2020 17:14:11
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;

int main() {
    vi a(3);
    rep(i,3) cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[1] << endl;
}