/**
*    author:  shu8Cream
*    created: 20.11.2021 20:46:00
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
    int n = 1048576;
    vi a(n,-1);
    int q; cin >> q;
    vvi next(n);
    rep(i,n) next[i].push_back(i);
    while(q--){
        int t; ll x; cin >> t >> x;
        if(t==1){
            ll h = x;
            while(next[h%n][0]!=h%n){
                ll s = h;
                h = next[h%n][0];
                next[s%n][0] = next[h%n][0];
            }
            a[next[h%n][0]] = x;
            next[h%n][0]++;
            next[h%n][0]%=n;
            next[x%n][0] = next[h%n][0];
        }else{
            cout << a[x%n] << endl;
        }
    }
}