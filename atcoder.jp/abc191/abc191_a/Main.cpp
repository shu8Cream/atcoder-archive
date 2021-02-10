/**
*    author:  shu8Cream
*    created: 10.02.2021 14:49:08
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
    int v,t,s,d;
    cin >> v >> t >> s >> d;
    cout << ((d<v*t || v*s<d) ? "Yes" : "No") << endl;
}