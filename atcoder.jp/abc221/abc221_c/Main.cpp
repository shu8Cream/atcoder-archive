/**
*    author:  shu8Cream
*    created: 02.10.2021 20:31:19
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
    string s; cin >> s;
    int n = sz(s);
    ll ans = 0;
    rep(bit,1<<n){
        string a="", b="";
        rep(i,n){
            if(bit>>i&1) a+=s[i];
            else b+=s[i];
        }
        sort(rall(a));
        sort(rall(b));
        if(a[0]=='0') continue;
        if(b[0]=='0') continue;
        if(a.empty()) continue;
        if(b.empty()) continue;
        debug(a,b);
        ll A = stoll(a);
        ll B = stoll(b);
        chmax(ans, A*B);
    }
    cout << ans << endl;
}