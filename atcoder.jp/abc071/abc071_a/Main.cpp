/**
*    author:  shu8Cream
*    created: 15.04.2021 20:58:22
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
    int x,a,b;
    cin >> x >> a >> b;
    cout << (abs(x-a)<abs(x-b) ? "A" : "B") << endl;
}