/**
*    author:  shu8Cream
*    created: 24.07.2021 21:43:12
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

int n,k;

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

ll ans = 0;
void dfs(vector<string> s){
    int cnt = 0;
    rep(i,n)rep(j,n) if(s[i][j]=='o') ++cnt;

    if(cnt==k) {ans++; return;}
    rep(i,n)rep(j,n){
        if(s[i][j]!='.') continue;
        if(cnt!=0){
            bool ok = false;
            rep(v,4){
                int ni = i+di[v], nj = j+dj[v];
                if(ni<0 || ni>=n || nj<0 || nj>=n) continue;
                if(s[ni][nj]=='o') ok = true;
            }
            if(!ok) continue;
        }
        s[i][j] = 'o';
        dfs(s);
        s[i][j] = '#';
        dfs(s);
        return;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    dfs(s);
    cout << ans << endl;
}