/**
*    author:  shu8Cream
*    created: 30.10.2021 22:12:25
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
// template<class T> inline bool chmin(T& a, T b) {
//     if (a > b) { a = b; return true; }
//     return false;
// }

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
    int n,k; cin >> n >> k;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    sort(rall(s), [&](auto a, auto b){
        return a+b < b+a;
    });

    vector<string> dp(k+1);
    auto chmin = [&](string &a, string b){
        if(b=="") return;
        if(a=="") { a=b; return; }
        a = min(a,b);
    };
    for(string a : s){
        for(int j=k-1; j>=0; j--){
            if(dp[j]=="" && j) continue;
            chmin(dp[j+1],a+dp[j]);
        }
    }
    cout << dp[k] << endl;
}