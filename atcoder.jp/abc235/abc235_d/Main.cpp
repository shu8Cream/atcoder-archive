/**
*    author:  shu8Cream
*    created: 15.01.2022 20:45:52
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,n; cin >> a >> n;
    queue<ll> q; q.push(1);
    map<ll,ll> mp;
    rep(i,2001001) mp[i] = INF;
    mp[1] = 0;
    ll ans = 0;
    while(!q.empty()){
        ll v = q.front(); q.pop();
        debug(v);
        if(v>n*10) continue;
        if(v<10){
            ll nv = v*a;
            if(mp[nv]<=mp[v]+1) continue;
            chmin(mp[nv],mp[v]+1);
            q.push(nv);
        }else{
            string t = to_string(v);
            if(v%10!=0){
                rotate(t.begin(),t.begin()+(sz(t)-1),t.end());
                debug(v,t);
                ll b = stoll(t);
                if(mp[b]>mp[v]+1){
                    chmin(mp[b],mp[v]+1);
                    q.push(b);
                }
            }
            ll nv = v*a;
            if(mp[nv]>mp[v]+1){
                chmin(mp[nv],mp[v]+1);
                q.push(nv);
            }
        }
    }
    if(mp[n]==INF) mp[n]=-1;
    cout << mp[n] << endl;
}