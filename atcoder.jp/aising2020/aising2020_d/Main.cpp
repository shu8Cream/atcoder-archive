/**
*    author:  shu8Cream
*    created: 20.01.2022 09:08:25
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

ll binToR(string x, ll m){
    ll res = 0;
    int n = sz(x);
    rep(i,n){
        ll c = x[i]-'0';
        res*=2;
        res+=c;
        res%=m;
    }
    return res;
}

ll mod_pow(ll a, ll b, ll n){
    if(b==0) return 1;
    if(b%2!=0) return a * mod_pow(a, b-1, n) % n;
    else return mod_pow(a * a % n, b / 2, n) % n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; string x; cin >> n >> x;

    vi vec(200200);
    vec[0] = 0;
    for(int i=1; i<200200; i++){
        ll c = 0;
        ll p = i;
        rep(j,19){
            c+=p%2;
            p/=2;
        }
        vec[i] = i%c;
    }
    debug(vec);

    ll cnt = 0;
    rep(i,n)if(x[i]=='1') cnt++;
    debug("init",cnt);
    ll r_minus = 0;
    if(cnt-1>0) r_minus = binToR(x,cnt-1);

    ll r_plus = binToR(x,cnt+1);

    rep(i,n){
        if(x[i]=='1'){
            if(cnt-1<=0){
                cout << 0 << endl;
                continue;
            }
            ll t = mod_pow(2,n-i-1,cnt-1);
            ll res = (r_minus-t+cnt-1)%(cnt-1);
            ll ans = 1;
            debug("res",res);
            while(res!=0){
                ans++;
                res = vec[res];
                debug("res",res);
            }
            cout << ans << endl;
        }else{
            ll t = mod_pow(2,n-i-1,cnt+1);
            ll res = (r_plus+t)%(cnt+1);
            ll ans = 1;
            debug("res",res);
            while(res!=0){
                ans++;
                res = vec[res];
                debug("res",res);
            }
            cout << ans << endl;
        }
    }
}