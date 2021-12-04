/**
*    author:  shu8Cream
*    created: 03.12.2021 20:26:00
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
    ll n,a,b; cin >> n >> a >> b;
    ll p,q,r,s; cin >> p >> q >> r >> s;
    q = q-p+1; s = s-r+1;
    a = a-p; b = b-r;
    vector<vector<char>> ans(q,vector<char>(s,'.'));
    
    if(0<=a && a<q && 0<=b && b<s){
        for(int i = 0; 0<=a+i && a+i<q && 0<=b+i && b+i<s; i++) ans[a+i][b+i] = '#';
        for(int i = 0; 0<=a-i && a-i<q && 0<=b-i && b-i<s; i++) ans[a-i][b-i] = '#';
        for(int i = 0; 0<=a+i && a+i<q && 0<=b-i && b-i<s; i++) ans[a+i][b-i] = '#';
        for(int i = 0; 0<=a-i && a-i<q && 0<=b+i && b+i<s; i++) ans[a-i][b+i] = '#';
    }else{
        rep(i,q) if(0<=a+b-i && a+b-i<s) ans[i][a+b-i] = '#';
        rep(i,s) if(0<=a-b+i && a-b+i<q) ans[a-b+i][i] = '#';
        
    }

    rep(i,q){
        rep(j,s) cout << ans[i][j];
        cout << endl;
    }
}