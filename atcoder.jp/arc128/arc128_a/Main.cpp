/**
*    author:  shu8Cream
*    created: 16.10.2021 20:55:17
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
    vi ans(n);
    int piv = 0, rem = -1;
    rep(i,n){
        if(rem>=0 && a[rem]<=a[i]){
            ans[piv] = 1;
            ans[rem] = 1;
            piv = i;
            rem = -1;
        }else if(a[piv]<=a[i]) piv = i;
        else if(rem==-1) rem = i;
        else if(a[rem]>a[i]) rem = i;
    }
    if(rem!=-1){
        ans[piv] = 1;
        ans[rem] = 1;
    }
    rep(i,n) cout << ans[i] << (i==n-1 ? "\n" : " ");
}