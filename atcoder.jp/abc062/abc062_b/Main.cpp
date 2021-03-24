/**
*    author:  shu8Cream
*    created: 24.03.2021 11:39:43
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<char>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> a(h+2,string(w+2,'#'));
    rep(i,h)rep(j,w) cin >> a[i+1][j+1];
    rep(i,h+2) cout << a[i] << endl;
}