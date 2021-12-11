/**
*    author:  shu8Cream
*    created: 11.12.2021 00:21:34",
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

const vi di = {1,0,-1,0};
const vi dj = {0,1,0,-1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w; cin >> h >> w;
    vvc c(h,vc(w));
    P start, goal;
    rep(i,h)rep(j,w){
        cin >> c[i][j];
        if(c[i][j]=='s') start = {i,j};
        if(c[i][j]=='g') goal = {i,j};
    }
    queue<P> q;
    q.push(start);
    vvi d(h,vi(w,INF));
    d[start.first][start.second] = 0;
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        if(d[goal.first][goal.second]<=2) break;
        rep(v,4){
            int ni = i+di[v];
            int nj = j+dj[v];
            if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
            if(c[ni][nj]=='#' && d[ni][nj]<=d[i][j]+1) continue;
            if(c[ni][nj]=='#' && d[ni][nj]>d[i][j]+1) d[ni][nj] = d[i][j]+1;
            if(c[ni][nj]!='#' && c[ni][nj]!='s' && d[ni][nj]<=d[i][j]) continue;
            if(c[ni][nj]!='#' && c[ni][nj]!='s' && d[ni][nj]>d[i][j]) chmin(d[ni][nj], d[i][j]);
            q.push({ni,nj});
        }
    }
    if(d[goal.first][goal.second]<=2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}