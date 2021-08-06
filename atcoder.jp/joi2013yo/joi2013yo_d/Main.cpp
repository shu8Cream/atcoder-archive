#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<ll>;
using vvi=vector<vi>;
using vs=vector<string>;
using P=pair<ll,ll>;

#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define range(i,m,n) for(int i=m; i<n;i++)
#define each(i,n) for(auto i:n)
#define all(i) i.begin(),i.end()
#define cint(...) int __VA_ARGS__;bulk(__VA_ARGS__);

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}

ll dp[220][220];

int main(void){
    int d,n; cin >> d >> n;
    vi t(d); rep(i,d) cin >> t[i];
    vi p(n); vector<P> temp(n);
    rep(i,n){
        int a,b,c; cin >> a >> b >> c;
        p[i] = c; temp[i] = {a,b};
    }
    rep(day,d)rep(i,n)rep(j,n){
        if(temp[j].first>t[day+1] || temp[j].second<t[day+1]) continue;
        if(temp[i].first>t[day] || temp[i].second<t[day]) continue;
        chmax(dp[day+2][j], dp[day+1][i] + abs(p[i] - p[j])); 
    }
    //rep(i,d){
    //    rep(j,n) cout << dp[i+1][j] << " ";
    //    cout << endl;
    //}
    ll ans = 0;
    rep(i,n) chmax(ans, dp[d][i]);
    cout << ans << endl;
}