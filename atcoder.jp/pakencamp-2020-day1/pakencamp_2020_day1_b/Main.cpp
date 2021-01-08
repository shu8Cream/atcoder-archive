/**
*    author:  shu8Cream
*    created: 08.01.2021 10:07:20
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
    string x;
    cin >> x;
    int ans = 0;
    rep(i,4){
        ans=max(ans, x[i]-'0');
    }
    cout << ans << endl;
}