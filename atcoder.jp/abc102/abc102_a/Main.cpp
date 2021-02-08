/**
*    author:  shu8Cream
*    created: 08.02.2021 21:48:43
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    cout << (n%2==0 ? n : 2*n) << endl;
}