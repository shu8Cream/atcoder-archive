/**
*    author:  shu8Cream
*    created: 05.06.2021 23:27:16
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,p,q;
    cin >> n >> p >> q;
    vi a(n); rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,n){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    for(int m=l+1; m<n; m++){
                        if(a[i]*a[j]%p*a[k]%p*a[l]%p*a[m]%p==q) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}