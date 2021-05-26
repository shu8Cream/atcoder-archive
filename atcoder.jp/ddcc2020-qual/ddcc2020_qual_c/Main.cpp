/**
*    author:  shu8Cream
*    created: 26.05.2021 09:45:52
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
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vvi a(h,vi(w));
    int cnt = 1;
    rep(i,h)rep(j,w){
        if(s[i][j]=='#') a[i][j]=cnt++;
    }
    rep(i,h)rep(j,w-1){
        if(a[i][j]!=0 && a[i][j+1]==0) a[i][j+1]=a[i][j]; 
    }
    rep(i,h)rrep(j,w){
        if(j==0) continue;
        if(a[i][j]!=0 && a[i][j-1]==0) a[i][j-1]=a[i][j]; 
    }
    rep(i,w)rep(j,h-1){
        if(a[j][i]!=0 && a[j+1][i]==0) a[j+1][i]=a[j][i]; 
    }
    rep(i,w)rrep(j,h){
        if(j==0) continue;
        if(a[j][i]!=0 && a[j-1][i]==0) a[j-1][i]=a[j][i]; 
    }
    rep(i,h){
        rep(j,w) cout << a[i][j] << " ";
        cout << endl;
    }
}