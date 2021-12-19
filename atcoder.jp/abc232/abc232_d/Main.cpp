/**
*    author:  shu8Cream
*    created: 19.12.2021 20:45:18
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

using vc = vector<char>;
using vvc = vector<vc>;

const vi di = {1,0};
const vi dj = {0,1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w; cin >> h >> w;
    vvc c(h,vc(w));
    rep(i,h)rep(j,w) cin >> c[i][j];
    vvi dist(h,vi(w,-1)); dist[0][0] = 1;
    queue<P> q; q.push({0,0});
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        rep(v,2){
            int ni = i+di[v], nj = j+dj[v];
            if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
            if(c[ni][nj]=='#')continue;
            if(dist[ni][nj]!=-1) continue;
            dist[ni][nj] = dist[i][j] + 1;
            q.push({ni,nj});
        }
    }
    ll ans = 0;
    rep(i,h)rep(j,w) chmax(ans,dist[i][j]);
    cout << ans << endl;
}