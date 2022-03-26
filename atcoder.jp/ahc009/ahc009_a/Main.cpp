/**
*    author:  shu8Cream
*    created: 26.03.2022 18:06:30
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

const int H = 20;
const int W = 20;

const vi di = {1,0,-1,0};
const vi dj = {0,1,0,-1};
const string direction = "DRUL";

int si,sj,ti,tj;
double p;
vv<char> h(20,vc<char>(19));
vv<char> v(19,vc<char>(20));
vvi field(H,vi(W));

bool out_of_grid(int x, int y){
    if(x<0 || x>=H || y<0 || y>=W) return true;
    return false;
}

bool is_not_through(int x, int y, int nx, int ny){
    if(x==nx) return h[x][min(y,ny)]-'0'==1;
    if(y==ny) return v[min(x,nx)][y]-'0'==1;
    return false;
}

int rndint(int l, int r){
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand(l, r);
    return rand(mt);
}

void input(){
    cin >> si >> sj >> ti >> tj >> p;
    rep(i,20) cin >> h[i];
    rep(i,19) cin >> v[i];
}

struct edge { int to; ll cost; };
vi dist;
vector<edge> G[440];
vi pre;

using namespace std::chrono;
inline double get_time_sec(void){
    return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    double start = get_time_sec();
    input();
    
    queue<P> q; q.push({si,sj});
    vvi seen(H,vi(W));
    bool f = false;
    while(sz(q)){
        auto[i,j] = q.front(); q.pop();
        debug(i,j);
        seen[i][j] = 1;
        rep(d,4){
            int pi = i, pj =j;
            int loop = 20;
            while(loop--){
                int ni = pi+di[d], nj = pj+dj[d];
                if(!out_of_grid(ni,nj) && seen[ni][nj]){
                    pi = ni; pj = nj;
                    continue;
                }
                if(out_of_grid(ni,nj) || is_not_through(pi,pj,ni,nj) || (ti==pi && tj==pj)){
                    if(!(pi==i && pj==j) && !seen[pi][pj]){
                        q.push({pi,pj});
                        G[i*H+j].push_back((edge){pi*H+pj,abs(i-pi)+abs(j-pj)});
                    }
                    break;
                }
                pi = ni; pj = nj;
            }
        }
    }

    bool stop = false;
    auto dijkstra = [&](int s) -> void{
        dist.resize(400,INF);
        pre.resize(400,-1);
        dist[s] = 0;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push(P(0, s));
        while (!q.empty()) {
            double end = get_time_sec();
            if(end-start>1.0){
                stop = true;
                break;
            }
            P p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (auto e : G[v]) {
                end = get_time_sec();
                if(end-start>1.0){
                    stop = true;
                    break;
                }
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    pre[e.to] = v;
                    q.push(P(dist[e.to], e.to));
                }
            }
        }
    };

    dijkstra(si*H+sj);

    vi path;
    for (int cur = ti*H+tj; cur != -1; cur = pre[cur]) {
        double end = get_time_sec();
        if(end-start>1.0){
            stop = true;
            break;
        }
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    
    cerr << path << endl;

    string ans = "";
    int now_i = si, now_j = sj;
    rep(i,sz(path)){
        double end = get_time_sec();
        if(end-start>1.0){
            stop = true;
            break;
        }
        int ni = path[i]/H;
        int nj = path[i]%H;
        int diff = dist[path[i]];
        if(i) diff-=dist[path[i-1]];
        diff *= 1.5;
        if(diff>=200){
            stop = true;
            break;
        }
        if(ni==now_i){
            if(nj>now_j){
                ans += string(diff,'R');
            }else{
                ans += string(diff,'L');
            }
        }else{
            if(ni>now_i){
                ans += string(diff,'D');
            }else{
                ans += string(diff,'U');
            }
        }
        if(sz(ans)>=10000){
            stop = true;
            break;
        }
        now_i = ni; now_j = nj;
    }
    cerr << sz(ans) << endl;
    while(sz(ans)>200) ans.pop_back();
    if(stop)ans = "DLDRDLDDRDUDRRURDLDDUDRDDRDDUDDLDDUDRLRDRRURRLRRRRDRURDRLDLDDRDDRDRRDDRDDRDDDDRDRRRRRRDRDRURURDRDDRDRRDDRDDRDDDDRDRRRRRRDRDRDRDDRDRRDDRDDRDDDDRDRRRRRRDRDRURURDRDDRDRRDDRDDRDDDDRDRRRRRRDRDRLDLDDRDDRDRR";
    cout << ans << endl;
    return 0;
}