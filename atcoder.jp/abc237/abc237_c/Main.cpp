/**
*    author:  shu8Cream
*    created: 30.01.2022 20:55:41
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

void naive(string s){
    int loop = 50;
    while(loop--){
        int n = sz(s);
        bool f = true;
        rep(i,n/2){
            if(s[i]!=s[n-1-i]) f = false;
        }
        s = 'a'+s;
        if(f){
            cout << s << endl;
            return;
        }
    }
    return;
}

vi rndvi(int l, int r, int len){
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand(l, r);
    vi res(len);
    rep(i,len) res[i] = rand(mt);
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vi tt = rndvi(0,1,10); 
    // string s;
    // rep(i,10) s+='a'+tt[i];
    string s; cin >> s;
    reverse(all(s));
    int cnt = 0;
    while(s.back()=='a'){
        s.pop_back();
        cnt++;
    }
    reverse(all(s));
    while(s.back()=='a'){
        s.pop_back();
        cnt--;
    }
    bool f = true;
    int n = sz(s);
    rep(i,n/2){
        if(s[i]!=s[n-1-i]) f = false;
    }
    debug(cnt);
    if(s.empty()) cnt=-1;
    cout << ((f && cnt<=0) ? "Yes":"No") << endl;
}