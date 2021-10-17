/**
*    author:  shu8Cream
*    created: 17.10.2021 20:46:32
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
    ll n; cin >> n;
    double time = 0;
    vector<double> a(n),b(n);
    double sum = 0;
    rep(i,n){
        cin >> a[i] >> b[i];
        time += a[i]/b[i];
        sum += a[i];
    }
    double ans = 0;
    time/=2.0;
    rep(i,n){
        if(time-a[i]/b[i]<0){
            ans += b[i]*time;
            break;
        }else{
            time-=a[i]/b[i];
            ans += a[i];
        }
    }
    printf("%.15lf\n", ans);
}