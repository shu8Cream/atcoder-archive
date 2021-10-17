/**
*    author:  shu8Cream
*    created: 17.10.2021 20:46:41
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
    priority_queue<ll, vector<ll>, greater<ll>> q;
    rep(i,n) if(in[i]==0) q.push(i);
    
    while(!q.empty()){
        int now = q.top(); q.pop();
        ans.push_back(now);
        for(auto p : to[now]){
            in[p]--;
            if(in[p]==0) q.push(p);
        }
    }
    return ans;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vvi to(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
    }
    vi tp = topsort(to);
    if(sz(tp)==n){
        rep(i,n) cout << tp[i]+1 << (n-1==i ? "\n" : " ");
    }else cout << -1 << endl;
}