/**
*    author:  shu8Cream
*    created: 02.01.2021 19:11:09
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
    int n,t;
    cin >> n >> t;
    vector<P> ct(n);
    rep(i,n) cin >> ct[i].second >> ct[i].first;
    sort(all(ct));
    int ans = 10000;
    rep(i,n){
        if(ct[i].first>t) break;
        ans=min(ans, ct[i].second);
    }
    if(ans==10000) cout << "TLE" << endl;
    else cout << ans << endl;
}