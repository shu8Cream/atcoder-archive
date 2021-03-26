/**
*    author:  shu8Cream
*    created: 26.03.2021 16:48:31
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
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<ll> a(n),cnt(m+1);
    rep(i,n){
        rep(j,m) if(s[i][j]=='1') a[i]++;
        cnt[a[i]]++;
    }
    ll ans = 0;
    rep(i,m){
        for(int j=i+1; j<m+1; j+=2){
            ans+=cnt[i]*cnt[j];
        }
    }
    cout << ans << endl;
}