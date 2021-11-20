/**
*    author:  shu8Cream
*    created: 20.11.2021 20:45:51
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    vvi p(n,vi(3));
    rep(i,n)rep(j,3) cin >> p[i][j];
    vector<P> sum(n);
    rep(i,n){
        ll tmp = 0;
        rep(j,3) tmp+=p[i][j];
        sum[i] = {tmp,i};
    }
    sort(all(sum));
    vi sco(n),id(n);
    rep(i,n){
        auto[sc,idx] = sum[i];
        sco[i] = sc;
        id[i] = idx;
    }
    vector<string> ans(n);
    rep(i,n){
        auto itr = upper_bound(all(sco),sco[i]+300) - sco.begin();
        debug(itr);
        if(n-itr+1<=k) ans[id[i]] = "Yes";
        else ans[id[i]] = "No";
    }
    rep(i,n) cout << ans[i] << endl;
}