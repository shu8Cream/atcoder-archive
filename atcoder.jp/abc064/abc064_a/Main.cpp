/**
*    author:  shu8Cream
*    created: 02.04.2021 22:37:51
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
    int r,g,b;
    cin >> r >> g >> b;
    cout << ((r*100+g*10+b)%4==0 ? "YES" : "NO") << endl;
}