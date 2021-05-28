/**
*    author:  shu8Cream
*    created: 27.05.2021 15:42:15
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
    ll n,k,p;
    cin >> n >> k >> p;
    vi a,b;
    rep(i,n){
        ll t; cin >> t;
        if(i%2==0) a.push_back(t);
        else b.push_back(t);
    }

    vvi A(k+1),B(k+1);
    rep(s,1<<a.size()){
        ll cnt = 0, sum = 0;
        rep(i,a.size()){
            if(s>>i&1){
                cnt++;
                sum += a[i];
            }
        }
        if(cnt>k) continue;
        A[cnt].push_back(sum);
    }
    rep(s,1<<b.size()){
        ll cnt = 0, sum = 0;
        rep(i,b.size()){
            if(s>>i&1){
                cnt++;
                sum += b[i];
            }
        }
        if(cnt>k) continue;
        B[cnt].push_back(sum);
    }
    rep(i,k+1) sort(all(A[i]));
    rep(i,k+1) sort(all(B[i]));
    ll ans = 0;
    rep(i,k+1)rep(j,A[i].size()){
        ll t = k-i;
        auto itr = upper_bound(all(B[t]), p-A[i][j]);
        ans += itr - B[t].begin();
    }
    cout << ans << endl;
}