/**
*    author:  shu8Cream
*    created: 09.10.2021 20:44:48
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
    ll n,m;
    cin >> n >> m;
    vector<string> a(2*n);
    rep(i,2*n) cin >> a[i];
    vi ans(2*n);
    vi win(2*n);
    rep(i,m){
        vector<P> player(2*n);
        rep(j,2*n) player[j] = {win[j],-j};
        sort(rall(player));
        // rep(j,2*n) cout << win[j] << endl;
        rep(j,n){
            int p1 = -player[2*j].second;
            int p2 = -player[2*j+1].second;
            auto pp1 = a[p1][i];
            auto pp2 = a[p2][i];
            if((pp1=='G' && pp2=='C') || (pp1=='P' && pp2=='G') || (pp1=='C' && pp2=='P')) win[p1]++;
            else if((pp2=='G' && pp1=='C') || (pp2=='P' && pp1=='G') || (pp2=='C' && pp1=='P')) win[p2]++;
        }
        // rep(j,2*n) cout << win[j] << endl;
    }
    vector<P> player(2*n);
    rep(i,2*n) player[i] = {win[i],-i};
    sort(rall(player));
    rep(i,2*n) cout << -player[i].second+1 << endl;
}