/**
*    author:  shu8Cream
*    created: 06.03.2021 20:47:30
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
    int a,b;
    cin >> a >> b;
    int ans = 0;
    if(a+b>=15 && b>=8) ans=1;
    else if(a+b>=10 && b>=3) ans=2;
    else if(a+b>=3) ans=3;
    else ans=4;
    cout << ans << endl;
}