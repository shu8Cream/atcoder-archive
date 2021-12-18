/**
*    author:  shu8Cream
*    created: 18.12.2021 10:57:31",
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

const int N = 20;
P start;
vector<string> WallW(N);
vector<string> WallH(N-1);
map<int,string> mp;

void INPUT(){
    cin >> start.first >> start.second;
    rep(i,N) cin >> WallW[i];
    rep(i,N-1) cin >> WallH[i];
    mp[0] = "L";
    mp[1] = "R";
    mp[2] = "l";
    mp[3] = "r";
    mp[4] = "F";
}

int rndint(int l, int r){
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand(l, r);
    return rand(mt);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    #ifdef _DEBUG
    FILE *fp;
    fp = fopen("./tools/out/0000.txt", "w");
    #endif
    INPUT();

    string ans = "";
    rep(i,5000){
        int a = rndint(0,4);
        ans += mp[a];
    }

    #ifdef _DEBUG
    fprintf(fp, "%s\n", ans.c_str());
    fclose(fp);
    #else
    cout << ans << endl;
    #endif
}