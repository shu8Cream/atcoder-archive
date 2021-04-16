/**
*    author:  shu8Cream
*    created: 16.04.2021 20:59:27
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

const int mod = 1e9+7;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; string s;
    cin >> n >> s;
    vi cnt(26);
    rep(i,n) cnt[s[i]-'a']++;
    ll ans = 1;
    rep(i,26) if(cnt[i]!=0){
        ans*=cnt[i]+1;
        ans%=mod;
    }
    cout << ans-1 << endl;
}