/**
*    author:  shu8Cream
*    created: 28.04.2021 22:32:31
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
    int a,b; string op;
    cin >> a >> op >> b;
    if(op=="+") cout << a+b << endl;
    else cout << a-b << endl;
}