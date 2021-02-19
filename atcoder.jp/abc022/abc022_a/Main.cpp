/**
*    author:  shu8Cream
*    created: 19.02.2021 12:13:16
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,s,t,w;
    cin >> n >> s >> t >> w;
    vi a(n);
    a[0]=w;
    rep(i,n-1){
        int b; cin >> b;
        a[i+1]=b+a[i];
    }
    int ans = 0;
    rep(i,n){
        if(s<=a[i] && a[i]<=t) ans++;
    } 
    cout << ans << endl;
}