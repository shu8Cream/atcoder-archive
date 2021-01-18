/**
*    author:  shu8Cream
*    created: 18.01.2021 11:44:57
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
    int h1,h2,m1,m2,k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int ans = 0;
    if(h1>h2) h2+=24;
    int hour = h2-h1;
    int minute = m2-m1;
    ans=hour*60+minute-k;
    cout << ans << endl;
}