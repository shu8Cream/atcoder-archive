/**
*    author:  shu8Cream
*    created: 23.01.2021 20:46:41
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
    string c;
    cin >> c;
    bool ok = false;
    if(c[0]==c[1] && c[1]==c[2]) ok = true;
    cout << (ok ? "Won" : "Lost") << endl;
}