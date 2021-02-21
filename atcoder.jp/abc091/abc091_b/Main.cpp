/**
*    author:  shu8Cream
*    created: 21.02.2021 17:50:53
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
    map<string,int> mp;
    rep(i,n){
        string s;
        cin >> s;
        mp[s]++;
    }
    int m; cin >> m;
    rep(i,m){
        string s;
        cin >> s;
        mp[s]--;
    }
    int ans = 0;
    for(auto p : mp){
        ans=max(ans,p.second);
    }
    cout << ans << endl;
}