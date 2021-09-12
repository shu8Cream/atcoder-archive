/**
*    author:  shu8Cream
*    created: 12.09.2021 14:29:58
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

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

struct Vegi{
    int r,c,s,e,v;
};

bool cmp(const Vegi &a, const Vegi &b){
    if(a.s != b.s)
        return a.s < b.s;
    if(a.v != b.v)
        return a.v > b.v;
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n,m,t; cin >> n >> m >> t;
    vector<Vegi> yasai(m);
    rep(i,m){
        cin >> yasai[i].r >> yasai[i].c >> yasai[i].s >> yasai[i].e >> yasai[i].v; 
    }
    
    sort(all(yasai), cmp);

    vvi ans(t);
    ans[0].push_back(yasai[0].r);
    ans[0].push_back(yasai[0].c);
    rep(i,t-1) ans[i+1].push_back(-1);
    
    rep(i,t){
        cout << ans[i][0];
        rep(j,sz(ans[i])-1) cout << " " << ans[i][j+1];
        cout << endl;
    }
}