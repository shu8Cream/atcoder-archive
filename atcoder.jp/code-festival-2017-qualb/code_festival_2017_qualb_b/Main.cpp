/**
*    author:  shu8Cream
*    created: 29.03.2021 16:56:35
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
    int n; cin >> n;
    vi d(n);
    rep(i,n) cin >> d[i];
    int m; cin >> m;
    vi t(m);
    rep(i,m) cin >> t[i];
    bool ok = true;
    map<int,int> mp;
    rep(i,n) mp[d[i]]++;
    rep(i,m){
        if(mp.count(t[i]) && mp[t[i]]>0){
            mp[t[i]]--;
        }else ok = false;
    }
    cout << (ok ? "YES" : "NO") << endl;
}