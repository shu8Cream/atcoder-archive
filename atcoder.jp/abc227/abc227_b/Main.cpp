/**
*    author:  shu8Cream
*    created: 13.11.2021 20:49:13
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
    vi s(n); rep(i,n) cin >> s[i];
    int ans = n;
    rep(i,n){
        bool f = false;
        rep(a,1000){
            rep(b,1000){
                if(4*(a+1)*(b+1)+3*(a+1)+3*(b+1)==s[i]){
                    ans--;
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
        if(f) continue;
    }
    cout << ans << endl;
}