/**
*    author:  shu8Cream
*    created: 22.12.2020 11:59:07
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vvi cnt(n,vi(26));
    rep(i,n)rep(j,s[i].size()){
        int tmp = s[i][j]-'a';
        cnt[i][tmp]++;
    }
    string ans;
    rep(i,26){
        int mn = 50;
        rep(j,n){
            mn = min(mn, cnt[j][i]);
        }
        rep(j,mn) ans+='a'+i;
    }
    cout << ans << endl;
}