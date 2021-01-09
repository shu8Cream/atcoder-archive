/**
*    author:  shu8Cream
*    created: 09.01.2021 14:57:54
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using vi = vector<int>; 

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int d,n;
    cin >> d >> n;
    int ans = pow(100,d) * n;
    if(n==100) ans+=pow(100,d);
    cout << ans << endl;
}