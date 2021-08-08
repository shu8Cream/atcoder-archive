/**
*    author:  shu8Cream
*    created: 08.08.2021 20:46:14
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
    ll h,w,n; cin >> h >> w >> n;
    vector<P> a(n),b(n);
    rep(i,n){
        cin >> a[i].first >> b[i].first;
        a[i].second = i;
        b[i].second = i;
    }
    sort(all(a)); sort(all(b));
    vector<P> ans(n);
    int cur1 = 1, cur2 = 1;
    rep(i,n){
        if(i && a[i-1].first==a[i].first)
            ans[a[i].second].first = cur1-1;
        else ans[a[i].second].first = cur1++;

        if(i && b[i-1].first==b[i].first)
            ans[b[i].second].second = cur2-1;
        else ans[b[i].second].second = cur2++;
    }
    rep(i,n) cout << ans[i].first << " " << ans[i].second << endl;
}