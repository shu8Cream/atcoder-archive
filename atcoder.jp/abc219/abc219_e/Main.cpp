/**
*    author:  shu8Cream
*    created: 18.09.2021 22:08:11
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

const vi di = {1,0,-1,0};
const vi dj = {0,1,0,-1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vvi a(4, vi(4));
    rep(i,4)rep(j,4) cin >> a[i][j];
    int ans = 0;
    rep(b,1<<16){
        vvi c(4, vi(4));
        int cnt = 0;
        rep(i,16){
            if(b>>i&1){
                c[i/4][i%4] = 1;
                cnt++;
            }
        }
        // if(b<=10){
        // rep(i,4){
        //     rep(j,4) cout << c[i][j] << " ";
        //     cout << endl;
        // }
        // }
        bool ng = false;
        P start = {-1,-1};
        rep(ii,4)rep(jj,4){
            if(a[ii][jj] && a[ii][jj]!=c[ii][jj]) ng = true;
            if(a[ii][jj] && a[ii][jj]==c[ii][jj]) start = {ii,jj};
        }
        if(ng) continue;
        vvi dist(4, vi(4,-1));
        queue<P> q;
        dist[start.first][start.second] = 0;
        q.push(start);
        int ccnt = 0;
        while (!q.empty()) {
            auto [I,J] = q.front(); q.pop();
            ccnt++;
            rep(k,4){
                int ni = I+di[k], nj = J+dj[k];
                if(ni<0 || ni>=4 || nj<0 || nj>=4) continue;
                if(dist[ni][nj]!=-1) continue;
                if(c[ni][nj]==0) continue;
                dist[ni][nj] = dist[I][J]+1;
                q.push({ni,nj});
            }
        }

        vvi dd(6,vi(6,-1));
        dd[0][0] = 0;
        q.push({0,0});
        int zznt = 0;
        while (!q.empty()) {
            auto [I,J] = q.front(); q.pop();
            zznt++;
            rep(k,4){
                int ni = I+di[k], nj = J+dj[k];
                if(ni<0 || ni>=6 || nj<0 || nj>=6) continue;
                if(dd[ni][nj]!=-1) continue;
                if(0<ni && ni<5 && 0<nj && nj<5 && c[ni-1][nj-1]==1) continue;
                dd[ni][nj] = dd[I][J]+1;
                q.push({ni,nj});
            }
        }

        if(zznt-20==16-cnt && cnt==ccnt) ans++;
    }
    cout << ans << endl;
}