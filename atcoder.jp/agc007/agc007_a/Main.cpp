/**
*    author:  shu8Cream
*    created: 29.03.2021 17:06:58
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
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int cnt = 0;
    rep(i,h)rep(j,w) if(s[i][j]=='#') cnt++;
    if(cnt!=h+w-1) cout << "Impossible" << endl;
    else cout << "Possible" << endl;
}