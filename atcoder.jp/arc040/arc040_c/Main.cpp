/**
*    author:  shu8Cream
*    created: 14.04.2021 13:41:20
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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans = 0, k = 0;
    rep(i,n){
        k=-1;
        rep(j,n) if(s[i][j]=='.') k=j;
        if(k>=0){
            ans++;
            if(i<n-1) for(int j=k; j<n;j++) s[i+1][j]='o';
        }
    }
    cout << ans << endl;
}