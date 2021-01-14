/**
*    author:  shu8Cream
*    created: 14.01.2021 14:38:49
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
    int n,k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    ll ans = 0;
    rep(i,min(n,k)+1){
        for(int j=0; i+j<=min(n,k); j++){
            vector<ll> s;
            ll now = 0;
            rep(l,i) s.push_back(v[l]), now+=v[l];
            rep(l,j) s.push_back(v[n-1-l]), now+=v[n-1-l];
            sort(all(s));
            rep(l,min(k-i-j, (int)s.size())){
                if(s[l]<0) now-=s[l];
            }
            ans=max(ans,now);
        }
    }
    cout << ans << endl;
}