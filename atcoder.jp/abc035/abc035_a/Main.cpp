/**
*    author:  shu8Cream
*    created: 25.01.2021 11:17:13
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int w,h;
    cin >> w >> h;
    cout << ((3*w==4*h) ? "4:3" : "16:9") << endl;
}