/**
*    author:  shu8Cream
*    created: 25.01.2021 11:17:17
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << ((n%2==0) ? n-1 : n+1) << endl;
}