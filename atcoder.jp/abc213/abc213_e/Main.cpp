/**
*    author:  shu8Cream
*    created: 08.08.2021 22:03:26
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

const vi di = {1,0,-1,0};
const vi dj = {0,1,0,-1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w; cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vvi dist(h,vi(w,10000));
    deque<P> q;
    dist[0][0]=0;
    q.push_back({0,0});
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop_front();
        rep(v,4){
            int ni = i+di[v];
            int nj = j+dj[v];
            if(ni<0 || nj<0 || ni>=h || nj>=w) continue;
            if (dist[ni][nj] > dist[i][j] && s[ni][nj] != '#'){
                q.push_front({ni,nj});
                dist[ni][nj] = dist[i][j];
            }
        }
        for(int x=-2; x<3; x++){
            for(int y=-1; y<3; y++){
                if(abs(x)+abs(y)==4) continue;
                int ni = i+x;
                int nj = j+y;
                if(ni<0 || nj<0 || ni>=h || nj>=w) continue;
                if(dist[ni][nj]>dist[i][j]+1){
                    dist[ni][nj]=dist[i][j]+1;
                    q.push_back({ni,nj});
                }
            }
        }
    }
    cout << dist[h-1][w-1] << endl;
}