/**
*    author:  shu8Cream
*    created: 09.03.2021 20:55:53
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

void rot(vvi& a){
    int h = a.size(); int w = a[0].size();
    vvi pre(w,vi(h));
    swap(a,pre);
    rep(i,w)rep(j,h) a[i][j]=pre[h-1-j][i];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vvi a(h,vi(w));
    rep(i,h)rep(j,w) a[i][j]=s[i][j]=='.';

    vvi ks = a;

    rep(v,4){
        vvi d(h,vi(w));
        rep(i,h){
            rep(j,w-1){
                if(a[i][j]) d[i][j]++;
                else d[i][j]=0;
                if(a[i][j+1]) ks[i][j+1]+=d[i][j];
                d[i][j+1]=d[i][j];
            }
        }
        rot(a);
        rot(ks);
        swap(h,w);
    }

    int ans = 0;
    rep(i,h)rep(j,w) ans=max(ans, ks[i][j]);
    cout << ans << endl;
}