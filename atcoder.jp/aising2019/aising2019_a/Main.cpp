/**
*    author:  shu8Cream
*    created: 24.12.2020 21:28:22
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,h,w;
    cin >> n >> h >> w;
    int ans = (n-h+1)*(n-w+1);
    cout << ans << endl;
}