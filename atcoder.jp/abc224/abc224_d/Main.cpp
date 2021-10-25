/**
*    author:  shu8Cream
*    created: 25.10.2021 23:56:41
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int m; cin >> m;
    vvi to(9);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    int p; string s = "999999999";
    rep(i,8){
        cin >> p;
        s[p-1] = i+'1';
    }
    debug(s);
    queue<string> q;
    q.push(s);
    map<string, int> mp;
    mp[s] = 0;

    while(!q.empty()){
        string s = q.front(); q.pop();
        int v;
        rep(i,9) if(s[i]=='9') v = i;
        for(auto nv : to[v]){
            string t = s;
            swap(t[v],t[nv]);
            if(mp.count(t)) continue;
            mp[t] = mp[s] + 1;
            q.push(t);
        }
    }
    if(mp.count("123456789")) cout << mp["123456789"] << endl;
    else cout << -1 << endl;
}