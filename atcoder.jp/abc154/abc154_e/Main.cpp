/**
*    author:  shu8Cream
*    created: 29.01.2022 11:06:10
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

template <class T> string to_string(T s);
template <class S, class T> string to_string(pair<S, T> p);
string to_string(char c) { return string(1, c); }
string to_string(string s) { return s; }
string to_string(const char s[]) { return string(s); }

template <class T>
string to_string(T v) {
    if (v.empty()) return "{}";
    string ret = "{";
    for (auto x : v) ret += to_string(x) + ",";
    ret.back() = '}';
    return ret;
}
template <class S, class T>
string to_string(pair<S, T> p) {
    return "{" + to_string(p.first) + ":" + to_string(p.second) + "}";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << to_string(H) << " ";
    debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

ll dp[105][4][2];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s; int k; cin >> s >> k;
    int n = sz(s);
    dp[1][1][1] = 1;
    rep(i,s[0]-'1') dp[1][1][0]++;
    dp[1][0][0] = 1;
    rep(i,n)rep(j,k+1){
        int c = s[i]-'0';
        if(j<k){
            dp[i+1][j+1][0] += dp[i][j][0]*9;
            dp[i+1][j+1][0] += dp[i][j][1]*max(0,c-1);
            dp[i+1][j][0] += dp[i][j][0];
            if(c!=0){
                dp[i+1][j][0] += dp[i][j][1];
                dp[i+1][j+1][1] += dp[i][j][1];
            }else dp[i+1][j][1] += dp[i][j][1];
        }else{
            if(c==0){
                dp[i+1][j][1] += dp[i][j][1];
                dp[i+1][j][0] += dp[i][j][0];
            }else{
                dp[i+1][j][0] += dp[i][j][1];
                dp[i+1][j][0] += dp[i][j][0];
            }
        }
    }
    debug(dp[3][1][0], dp[2][1][0],dp[2][0][0]);
    cout << dp[n][k][0]+dp[n][k][1] << endl;
}