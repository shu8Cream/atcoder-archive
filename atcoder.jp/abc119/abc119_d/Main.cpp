/**
*    author:  shu8Cream
*    created: 12.10.2021 22:15:42
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
    int a,b,q; cin >> a >> b >> q;
    vi s(a),t(b);
    rep(i,a) cin >> s[i];
    rep(i,b) cin >> t[i];
    sort(all(s));
    sort(all(t));
    rep(i,q){
        ll x; cin >> x;
        int itr1 = lower_bound(all(s), x) - s.begin();
        int itr2 = lower_bound(all(t), x) - t.begin();
        ll ans = INF;
        if(x<=s[itr1] && s[itr1]<=t[itr2]){
            ans = t[itr2]-x;
        }else if(x<=t[itr2] && t[itr2]<=s[itr1]){
            ans = s[itr1]-x;
        }

        if(itr1 && itr2<b){
            ll tmp = x-s[itr1-1] + t[itr2]-s[itr1-1];
            chmin(ans,tmp);
            tmp = t[itr2]-x + t[itr2]-s[itr1-1];
            chmin(ans,tmp);
        }
        if(itr2 && itr1<a){
            ll tmp = x-t[itr2-1] + s[itr1]-t[itr2-1];
            chmin(ans,tmp);
            tmp = s[itr1]-x + s[itr1]-t[itr2-1];
            chmin(ans,tmp);
        }
        if(itr1 && itr2){
            ll a = min(s[itr1-1], t[itr2-1]);
            ll tmp = x-a;
            chmin(ans,tmp);
        }
        cout << ans << endl;
    }
}