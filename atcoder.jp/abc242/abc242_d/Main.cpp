/**
*    author:  shu8Cream
*    created: 05.03.2022 20:36:42
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
    string s; int q; cin >> s >> q;
    int n = sz(s);
    rep(_,q){
        ll t,k; cin >> t >> k;
        ll id = k-1;
        int cnt = 0;
        rep(i,t){
            id/=2;
            cnt++;
            if(id==0) break;
        }
        debug(id);
        if(cnt==t){
            vi r;
            ll tmp = k-1;
            while(cnt--){
                if(tmp%2) r.push_back(1);
                else r.push_back(0);
                tmp/=2;
            }
            char ans = s[id];
            rrep(j,sz(r)){
                if(ans=='A'){
                    if(r[j]) ans = 'C';
                    else ans = 'B';
                }else if(ans=='B'){
                    if(r[j]) ans = 'A';
                    else ans = 'C';
                }else{
                    if(r[j]) ans = 'B';
                    else ans = 'A';
                }
            }
            cout << ans << endl;
        }else{
            vi r;
            ll tmp = k-1;
            ll loop = cnt;
            while(loop--){
                if(tmp%2) r.push_back(1);
                else r.push_back(0);
                tmp/=2;
            }
            ll p = (t-cnt)%3;
            char ans = 'A' + ((s[0]-'A')+p)%3;
            debug(ans,r);
            rrep(j,sz(r)){
                if(ans=='A'){
                    if(r[j]) ans = 'C';
                    else ans = 'B';
                }else if(ans=='B'){
                    if(r[j]) ans = 'A';
                    else ans = 'C';
                }else{
                    if(r[j]) ans = 'B';
                    else ans = 'A';
                }
            }
            cout << ans << endl;
        }
    }
}