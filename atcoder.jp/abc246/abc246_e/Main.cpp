/**
*    author:  shu8Cream
*    created: 26.04.2022 22:33:32
**/

#include <bits/stdc++.h>
using namespace std;
#define overload3(a,b,c,d,...) d
#define rep1(i,n) for (int i=0; i<(n); i++)
#define rep2(i,a,n) for (int i=(a); i<(n); i++)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define rrep1(i,n) for (int i=(n-1); i>=0; i--)
#define rrep2(i,a,n) for (int i=(n-1); i>=(a); i--)
#define rrep(...) overload3(__VA_ARGS__, rrep2, rrep1)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define pcnt __builtin_popcountll
using ll = long long;
using P = pair<ll,ll>;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vi = vc<ll>;
using vvi = vv<ll>;
const ll INF = 8e18;
template<typename T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const T&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.first>>v.second;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.first<<","<<v.second;}
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

const vi di = {1,-1,-1,1};
const vi dj = {1,1,-1,-1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int n; cin >> n;
    int ax,ay,bx,by; cin >> ax >> ay >> bx >> by;
    vc<string> s(n); cin >> s;
    vvi dist(n,vi(n,INF)); dist[ax-1][ay-1]=0;
    queue<P> q; q.push({ax-1,ay-1});

    auto out_of_grid = [&](int x, int y)->bool{
        if(x<0 || x>=n || y<0 || y>=n) return true;
        return s[x][y]=='#';
    };

    while(sz(q)){
        auto[i,j] = q.front(); q.pop();
        rep(v,4){
            int ni = i, nj = j;
            int d = dist[ni][nj];
            while(1){
                ni += di[v];
                nj += dj[v];
                if(out_of_grid(ni,nj))break;
                if(dist[ni][nj]>d+1){
                    dist[ni][nj] = d+1;
                    q.push({ni,nj});
                }else if(dist[ni][nj]==d+1){
                    q.push({ni,nj});
                }else break;
            }
        }
    }
    ll ans = 0;
    if(dist[bx-1][by-1]==INF) ans = -1;
    else ans = dist[bx-1][by-1];
    cout << ans << endl;
}