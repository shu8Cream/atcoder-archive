/**
*    author:  shu8Cream
*    created: 09.02.2022 21:30:21
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

void solve(){
    ll n; cin >> n;
    map<ll,vi> mp;
    ll cur = INF;
    rep(i,n){
        ll l,r; cin >> l >> r;
        mp[l].push_back(r);
        chmin(cur,l);
    }
    mp[INF].push_back(INF);
    priority_queue<ll, vi, greater<ll>> q;
    bool f = true;
    while(cur<=1000000000){
        for(auto x:mp[cur]) q.push(x);
        ll x = q.top(); q.pop();
        if(q.empty()){
            auto it = mp.lower_bound(cur+1);
            cur = it->first;
            debug(cur);
        }else{
            if(q.top()<=cur){
                f = false;
                break;
            }
            cur++;
        }
    }
    cout << (f ? "Yes":"No") << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
}