/**
*    author:  shu8Cream
*    created: 28.11.2021 20:52:39
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define Rep(i,x,n) for (int i=(x); i<n; i++)
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
string to_string(T s);
template <class S, class T>
string to_string(pair<S, T> p);
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
    string a,b; cin >> a >> b;
    int na = sz(a), nb = sz(b);
    int swp = 0;
    if(na>nb){
        swap(a,b);
        swap(na,nb);
        swp = 1;
    }
    vi cnta(10), cntb(10);
    for(char c:a) cnta[c-'0']++;
    for(char c:b) cntb[c-'0']++;
    int n = max(na,nb);
    cnta[0]=n-na;
    cntb[0]=n-nb;
    debug(n-na, n-nb);
    debug(cnta,cntb);

    pair<string,string> ans(a,b);

    ll best = 0;
    Rep(x,1,10)if(cnta[x]>0){
        Rep(y,1,10)if(cntb[y]>0){
            if(x+y>=10){
                cnta[x]--;
                cntb[y]--;
                FordFulkerson<int> g(22);
                rep(i,10){
                    g.add_edge(20,i,cnta[i]);
                    g.add_edge(10+i,21,cntb[i]);
                    rep(j,10) if(i+j>=9) g.add_edge(i,10+j,1e9);
                }
                ll flow = g.max_flow(20,21);
                debug(flow);
                if(flow>best){
                    string ta,tb;
                    vi tca = cnta, tcb = cntb;
                    rep(i,10){
                        for(auto&e : g.graph[i]){
                            if(e.isrev || e.to==10) continue;
                            auto& rev_e = g.graph[e.to][e.rev];
                            if(rev_e.cap==0) continue;
                            ta+=string(rev_e.cap,'0'+i);
                            tb+=string(rev_e.cap,'0'+e.to-10);
                            tca[i] -= rev_e.cap;
                            tcb[e.to-10] -= rev_e.cap;
                        }
                    }

                    debug(cnta, cntb);

                    ta+='0'+x;
                    tb+='0'+y;

                    reverse(all(ta));
                    reverse(all(tb));
                    rep(i,10) ta+=string(tca[i],'0'+i);
                    rep(i,10) tb+=string(tcb[i],'0'+i);
                    reverse(all(ta));
                    reverse(all(tb));
                    string TA;
                    for(char c:ta) if(c=='0') TA+=c;
                    for(char c:ta) if(c!='0') TA+=c;
                    ta=TA;
                    best = flow;
                    ans = {ta,tb};
                }
                cnta[x]++;
                cntb[y]++;
            }
        }
    }
    if (swp) swap(ans.first, ans.second);
    reverse(all(ans.first));
    while (ans.first.back() == '0') ans.first.pop_back();
    reverse(all(ans.first));
    reverse(all(ans.second));
    while (ans.second.back() == '0') ans.second.pop_back();
    reverse(all(ans.second));
    cout << ans.first << endl;
    cout << ans.second << endl;
}