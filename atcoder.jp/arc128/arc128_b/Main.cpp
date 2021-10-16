/**
*    author:  shu8Cream
*    created: 16.10.2021 20:55:24
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll INF = 8e18;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
cout << H << " ";
debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void solve(){
    vi a(3);  rep(i,3) cin >> a[i];
    sort(all(a));
    ll ans = INF;
    if((a[1]-a[0])%3==0){
        ll tmp = (a[1]-a[0])/3;
        tmp += (a[0] + 2*tmp);
        chmin(ans,tmp);
    }
    if((a[2]-a[1])%3==0){
        ll tmp = (a[2]-a[1])/3;
        tmp += (a[1] + 2*tmp);
        chmin(ans,tmp);
    }
    if((a[2]-a[0])%3==0){
        ll tmp = (a[2]-a[0])/3;
        tmp += (a[0] + 2*tmp);
        chmin(ans,tmp);
    }
    cout << (ans==INF ? -1 : ans) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
}