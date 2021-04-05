/**
*    author:  shu8Cream
*    created: 05.04.2021 21:39:47
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
    int n;
    cin >> n;
    int ans = 0;
    if(n<=111) ans=111;
    else if(n<=222) ans=222;
    else if(n<=333) ans=333;
    else if(n<=444) ans=444;
    else if(n<=555) ans=555;
    else if(n<=666) ans=666;
    else if(n<=777) ans=777;
    else if(n<=888) ans=888;
    else if(n<=999) ans=999;
    cout << ans << endl;
}