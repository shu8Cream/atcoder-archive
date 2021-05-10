/**
*    author:  shu8Cream
*    created: 10.05.2021 20:43:06
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    int n = s.size();
    int ans = 0, nico = 0;
    bool ok = true;
    rep(i,n){
        if(s[i]=='2') nico++;
        else nico--;
        if(nico<0) ok = false;
        ans = max(ans,nico);
    }
    if(nico!=0) ok = false;
    if(!ok) ans = -1;
    cout << ans << endl;
}