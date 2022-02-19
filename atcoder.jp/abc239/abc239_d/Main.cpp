/**
*    author:  shu8Cream
*    created: 19.02.2022 20:34:48
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

struct Sieve{
    int n;
    vector<int> f,primes;
    Sieve(int n=1):n(n+1),f(n+1){
        f[0] = f[1] = -1;
        for(ll i=2; i<=n; ++i){
            if(f[i]) continue;
            primes.push_back(i);
            f[i]=i;
            for(ll j=i*i; j<=n; j+=i){
                if(!f[j]) f[j]=i;
            }
        }
    }

    bool isPrime(int x){ return f[x]==x;}

    vector<int> factorList(int x){
        vector<int> res;
        while(x!=1){
            res.push_back(f[x]);
            x/=f[x];
        }
        return res;
    }

    vector<P> factor(int x){
        vector<int> fl = factorList(x);
        if(fl.size()==0) return {};
        vector<P> res(1,P(fl[0], 0));
        for(int p : fl){
            if(res.back().first == p){
                res.back().second++;
            }else{
                res.emplace_back(p,1);
            }
        }
        return res;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    Sieve sieve(1000);
    int a,b,c,d; cin >> a >> b >> c >> d;
    for(int i=a; i<=b; i++){
        bool tak = true;
        for(int j=c; j<=d; j++){
            if(sieve.isPrime(i+j)) tak = false;
        }
        if(tak){
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
}