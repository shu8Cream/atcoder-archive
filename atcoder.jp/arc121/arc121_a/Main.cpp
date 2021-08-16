/**
*    author:  shu8Cream
*    created: 09.08.2021 13:16:56
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
    ll n; cin >> n;
    vector<pair<ll,P>> xy(n),yx(n);
    vi x(n),y(n);
    rep(i,n){
        ll a,b; cin >> a >> b;
        x[i] = a;
        y[i] = b;
        xy[i] = {a,{b,i}};
        yx[i] = {b,{a,i}};
    }
    sort(all(xy));
    sort(all(yx));
    set<P> remIdx;
    remIdx.insert({xy[n-1].second.second, xy[1].second.second});
    remIdx.insert({xy[n-2].second.second, xy[0].second.second});
    remIdx.insert({xy[n-1].second.second, xy[0].second.second});
    remIdx.insert({yx[n-1].second.second, yx[1].second.second});
    remIdx.insert({yx[n-2].second.second, yx[0].second.second});
    remIdx.insert({yx[n-1].second.second, yx[0].second.second});
    vi ans;
    for(auto [f,s] : remIdx){
        ll p = max(abs(x[f]-x[s]), abs(y[f]-y[s]));
        ans.push_back(p);
    }
    sort(rall(ans));
    cout << ans[1] << endl;
}