/**
*    author:  shu8Cream
*    created: 17.11.2021 17:59:06
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

const vi dx = {-1,0,1,0};
const vi dy = {0,-1,0,1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w; cin >> h >> w;
    vvi a(h,vi(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    vector<pair<P,P>> ans;
    rep(i,h)rep(j,w){
        if(a[i][j]%2==0) continue;
        if(j==w-1){
            if(i==h-1) continue;
            a[i][j]--;
            a[i+1][j]++;
            ans.push_back({{i,j},{i+1,j}});
        }else{
            a[i][j]--;
            a[i][j+1]++;
            ans.push_back({{i,j},{i,j+1}});
        }
    }
    cout << sz(ans) << endl;
    rep(i,sz(ans)){
        auto [F,S] = ans[i];
        auto [ff,fs] = F;
        auto [sf,ss] = S;
        ff++; fs++; sf++; ss++;
        cout << ff << " " << fs << " " << sf << " " << ss << endl;
    }
}