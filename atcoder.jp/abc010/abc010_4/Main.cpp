/**
*    author:  shu8Cream
*    created: 24.03.2022 22:51:02
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

template<typename flow_t>
struct FordFulkerson {
    struct edge {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
        int idx;
    };

    vector<vector<edge>> graph;
    vector<int> used;
    const flow_t INF;
    int timestamp;

    FordFulkerson(int n) : INF(numeric_limits<flow_t>::max()), timestamp(0) {
        graph.resize(n);
        used.assign(n,-1);
    }

    void add_edge(int from, int to, flow_t cap, int idx = -1){
        graph[from].emplace_back((edge){to,cap,sz(graph[to]),false,idx});
        graph[to].emplace_back((edge){from,0,sz(graph[from])-1,true,idx});
    }

    // graph[to][rev]は逆辺
    flow_t dfs(int idx, const int t, flow_t flow){
        if(idx==t) return flow;
        used[idx] = timestamp;
        for(auto &e: graph[idx]){
            if(e.cap>0 && used[e.to]!=timestamp){
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if(d>0){
                    e.cap-=d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t){
        flow_t flow = 0;
        for(flow_t f; (f = dfs(s,t,INF))>0; timestamp++){
            flow += f;
        }
        return flow;
    }

    void output(){
        rep(i,sz(graph)){
            for(auto &e: graph[i]){
                if(e.isrev) continue;
                auto &rev_e = graph[e.to][e.rev];
                debug(i,"->", e.to, " (flow: ", rev_e.cap, "/", e.cap + rev_e.cap, ")");
            }
        }
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,g,e; cin >> n >> g >> e;
    vc<int> p(g); cin >> p;
    FordFulkerson<ll> G(n+1);
    rep(i,e){
        int u,v,c; cin >> u >> v;
        G.add_edge(u,v,1,i);
        G.add_edge(v,u,1,i);
    }
    rep(i,g) G.add_edge(p[i],n,1,e+i);
    G.output();
    cout << G.max_flow(0,n) << endl;
}