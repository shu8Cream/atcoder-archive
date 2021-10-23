/**
*    author:  shu8Cream
*    created: 23.10.2021 20:54:46
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
    int n; cin >> n;
    vector<P> xy(n);
    rep(i,n){
        ll x,y;cin >> x >> y;
        xy[i] = {x,y};
    }
    ll all = n*(n-1)*(n-2)/6;
    ll cnt = 0;
    rep(i,n)for(int j=i+1; j<n; j++){
        for(int k=j+1; k<n; k++){
            auto [x1,y1] = xy[i];
            auto [x2,y2] = xy[j];
            auto [x3,y3] = xy[k];
            if((x1-x2)*y3==(y1-y2)*x3+(x1-x2)*y1-(y1-y2)*x1) all--;
        }
    }
    cout << all << endl;
}