/**
*    author:  shu8Cream
*    created: 05.12.2021 21:49:58",
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

const vi di = {1,0,-1,0};
const vi dj = {0,1,0,-1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w; cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    rep(i,h)rep(j,w){
        if(c[i][j]!='.') continue;
        set<int> se;
        rep(i,5) se.insert(i+1);
        rep(v,4){
            int ni = i+di[v], nj = j+dj[v];
            if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
            if(c[ni][nj]=='1') se.erase(1);
            if(c[ni][nj]=='2') se.erase(2);
            if(c[ni][nj]=='3') se.erase(3);
            if(c[ni][nj]=='4') se.erase(4);
            if(c[ni][nj]=='5') se.erase(5);
        }
        c[i][j] = char('0' + *begin(se));
    }
    rep(i,h) cout << c[i] << endl;
}