/**
*    author:  shu8Cream
*    created: 01.05.2021 23:10:58
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
    int n;
    cin >> n;
    string ans = "";
    if(n<100) ans = "00";
    else if(100<=n && n<1000) ans = "0" + to_string(n/100);
    else if(1000<=n && n<=5000) ans = to_string(n/100);
    else if(3600<=n && n<=30000) ans = to_string(n/1000+50);
    else if(35000<=n && n<=70000) ans = to_string((n/1000-30)/5+80);
    else ans = "89";
    cout << ans << endl;
}