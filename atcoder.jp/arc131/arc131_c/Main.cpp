/**
*    author:  shu8Cream
*    created: 05.12.2021 22:01:10",
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

void random_generate(int n, vi &A){
    rep(i,n) A[i] = rand()%100 + 1;
}

void naive(int n, vi &A){
    ll sum = 0;
    rep(i,n) sum^=A[i];
    debug(sum);
    debug(A);
    rep(i,n){
        vi B;
        rep(j,n) if(i!=j) B.push_back(A[j]);
        naive(n-1,B);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];

    // vi b(n); random_generate(n,b);
    // naive(n,b);

    if(n%2!=0){
        cout << "Win" << endl;
        return 0;
    }

    ll sum = 0;
    rep(i,n) sum^=a[i];
    vi gr(n);
    rep(i,n) gr[i] = sum^a[i];
    debug(gr);
    rep(i,n) if(gr[i]==0){
        cout << "Win" << endl;
        return 0;
    }

    cout << "Lose" << endl;
}