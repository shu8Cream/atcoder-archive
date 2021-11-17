/**
*    author:  shu8Cream
*    created: 17.11.2021 00:06:29
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
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    sort(all(a));
    ll ans = 0;
    if(n%2==0){
        rep(i,n/2) ans+=2*a[n-1-i];
        rep(i,n/2) ans-=2*a[i];
        ans = ans - a[n/2] + a[n/2-1];
    }else{
        rep(i,n/2) ans+=2*a[n-1-i];
        rep(i,n/2) ans-=2*a[i];
        ll mid = a[n/2];
        ans = max(ans-mid+a[n/2-1], ans+mid-a[n-n/2]); 
    }
    cout << ans << endl;
}