/**
*    author:  shu8Cream
*    created: 27.11.2021 20:50:17
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
    string s; ll k;
    cin >> s >> k;
    int n = sz(s);
    int ans = 0;
    int r = 0;
    int tk = k;
    rep(l,n){
        while(r<n){
            if(s[r]=='X'){
                r++;
            }else if(s[r]=='.' && tk){
                tk--; r++;
            }else  break;
        }
        debug(l,r);
        chmax(ans, r-l);
        if(r<=l) r=l+1;
        if(s[l]=='.' && tk+1<=k) tk++;
    }
    cout << ans << endl;
}