/**
*    author:  shu8Cream
*    created: 11.02.2021 13:00:05
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vector<vector<char>> a(10, vector<char>(10));

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

bool seen[12][12];
void dfs(int h, int w){
    seen[h][w] = true;
    a[h][w]='x';
    rep(i,4){
        int nh = h + dx[i];
        int nw = w + dy[i];
        if(nh<0 || nh>=10 || nw<0 || nw>=10) continue;
        if(a[nh][nw]=='x') continue;
        if(seen[nh][nw]) continue;
        dfs(nh,nw);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    bool ok = true;
    rep(i,10)rep(j,10){
        cin >> a[i][j];
        if(a[i][j]=='o'){
            h=i;
            w=j;
        }
    }
    vector<vector<char>> aa(10, vector<char>(10));
    rep(i,10)rep(j,10) aa[i][j]=a[i][j];
    dfs(h,w);
    rep(i,10)rep(j,10) if(a[i][j]=='o') ok = false;
    if(ok){
        cout << "YES" << endl;
        return 0; 
    }
    rep(i,10)rep(j,10){
        rep(ii,10)rep(jj,10){
            a[ii][jj]=aa[ii][jj];
            seen[ii][jj]=false;
        }
        if(a[i][j]=='o') continue;
        ok = true;
        a[i][j]='o';
        dfs(i,j);
        rep(ii,10)rep(jj,10) if(a[ii][jj]=='o') ok = false;
        if(ok){
            cout << "YES" << endl;
            return 0; 
        }
    }
    cout << "NO" << endl;
}