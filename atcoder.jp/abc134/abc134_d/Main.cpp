/**
*    author:  shu8Cream
*    created: 17.11.2021 10:38:38
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
    vi a(n); rep(i,n) cin >> a[i];
    vi ans(n,-1);
    rrep(i,n){
        if(a[i]==0){
            int j = i;
            int cnt = 0;
            while(j<n-1){
                j+=i+1;
                if(j>=n) break;
                if(ans[j]) cnt++;
            }
            if(cnt%2==0) ans[i] = 0;
            else ans[i] = 1;
        }else{
            int j = i;
            int cnt = 0;
            while(j<n-1){
                j+=i+1;
                if(j>=n) break;
                if(ans[j]) cnt++;
            }
            if(cnt%2==0) ans[i] = 1;
            else ans[i] = 0;
        }
    }
    vi res;
    rep(i,n) debug(ans[i]);
    rep(i,n) if(ans[i]) res.push_back(i+1);
    cout << sz(res) << endl;
    rep(i,sz(res)) cout << res[i] << endl;
}