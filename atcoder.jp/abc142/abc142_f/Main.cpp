/**
*    author:  shu8Cream
*    created: 06.11.2021 21:58:40
**/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

vi topsort(vvi &to){
    vi ans;
    int n = sz(to);
    vi in(n);
    rep(i,n){
        for(auto p : to[i]) in[p]++;
    }
    queue<int> q;
    rep(i,n) if(in[i]==0) q.push(i);
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        ans.push_back(now);
        for(auto p : to[now]){
            in[p]--;
            if(in[p]==0) q.push(p);
        }
    }
    return ans;
}

vi bfs(int s, vvi &to){
    int n = sz(to);
    vi dist(n, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int nv : to[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    return dist;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vvi to(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
    }
    vi tp = topsort(to);
    if(sz(tp)==n){
        cout << -1 << endl;
        return 0;
    }
    int shortest = n+1;
    vi res;
    rep(i,n){
        vi dist(n, -1);
        vi prev(n, -1);
        queue<int> q;
        dist[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int nv : to[v]) {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                prev[nv] = v;
                q.push(nv);
            }
        }
        rep(j,n){
            if(j==i || dist[j]==-1) continue;
            for(auto nx : to[j]){
                if(nx==i){
                    vi tmp; tmp.push_back(i);
                    int cur = j;
                    while(cur!=i){
                        tmp.push_back(cur);
                        cur = prev[cur];
                    }
                    if(shortest>sz(tmp)){
                        shortest = sz(tmp);
                        res = tmp;
                    }
                }
            }
        }
    }
    cout << sz(res) << endl;
    for(auto p : res) cout << p+1 << endl;
    
}