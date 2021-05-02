/**
*    author:  shu8Cream
*    created: 02.05.2021 10:37:44
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int ans = 0;
    rep(i,9){
        if(s.substr(i,4)=="ZONe") ans++;
    }
    cout << ans << endl;
}