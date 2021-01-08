/**
*    author:  shu8Cream
*    created: 08.01.2021 10:07:36
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
        int k; cin >> k;
        rep(i,k){
            string s; cin >> s;
            mp[s]++;
        }
    }
    int ans = 0;
    for(auto p : mp){
        if(p.second==n) ans++;
    }
    cout << ans << endl;
}