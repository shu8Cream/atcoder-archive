/**
*    author:  shu8Cream
*    created: 22.11.2021 14:18:37
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
    priority_queue<ll,vi,greater<ll>> a,b,c;
    rep(i,n) { int p; cin >> p; a.push(p); }
    rep(i,n) { int p; cin >> p; b.push(p); }
    rep(i,n) { int p; cin >> p; c.push(p); }
    int ans = 0;
    while(!a.empty()){
        int ta = a.top(); a.pop();
        while(!b.empty() && b.top() <= ta) b.pop();
        if(b.empty()) break;
        int tb = b.top();
        while(!c.empty() && c.top() <= tb) c.pop();
        if(c.empty()) break;
        ans++;
        b.pop();
        c.pop();
    }
    cout << ans << endl;
}