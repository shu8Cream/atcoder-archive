/**
*    author:  shu8Cream
*    created: 09.02.2021 15:33:39
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    int ans = 0;
    int c = 0;
    rep(i,b-a) c+=i+1;
    cout << c-b << endl;
}