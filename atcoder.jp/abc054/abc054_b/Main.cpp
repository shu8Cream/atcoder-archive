/**
*    author:  shu8Cream
*    created: 28.12.2020 00:40:19
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int n,m;

bool solve(vector<string> a, vector<string> b){
    rep(i,n-m+1){
        rep(j,n-m+1){
            bool ng = false;
            rep(k,m){
                rep(l,m){
                    if(a[i+k][j+l]!=b[k][l]) ng=true;
                }
                if(ng) break;
            }
            if(!ng) return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    vector<string> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    
    cout << (solve(a,b) ? "Yes" : "No") << endl;
}