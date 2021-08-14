/**
*    author:  shu8Cream
*    created: 14.08.2021 13:54:59
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vvi to(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
    }
    ll ans = 0;
    rep(_,n){
        vi dist(n,-1);
        queue<ll> q;
        dist[_]=0;
        q.push(_);
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(auto nv : to[v]){
                if(dist[nv]!=-1) continue;
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }
        rep(i,n) if(dist[i]!=-1) ans++;
    }
    cout << ans << endl;
}