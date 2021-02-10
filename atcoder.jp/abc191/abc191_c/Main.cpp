/**
*    author:  shu8Cream
*    created: 10.02.2021 14:49:29
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int dx[] = {1,0,1};
const int dy[] = {0,1,1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    rep(i,h-1)rep(j,w-1){
        int cnt = 0;
        if(s[i][j]=='#') cnt++;
        rep(k,3){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(s[ni][nj]=='#') cnt++;
        }
        if(cnt==1 || cnt==3) ans++;
    }
    cout << ans << endl;
}