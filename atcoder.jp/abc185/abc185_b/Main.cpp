/**
*    author:  shu8Cream
*    created: 13.12.2020 21:01:50
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    int n,m,t;
    cin >> n >> m >> t;
    vi a(m),b(m);
    rep(i,m) cin >> a[i] >> b[i];
    bool f0=false;
    int fulln=n;
    rep(i,m){
        if(i==0) n-=a[i];
        if(n<=0) f0=true;
        n+=b[i]-a[i];
        if(fulln<n) n=fulln;
        if(i!=m-1) n-=a[i+1]-b[i];
        else n-=t-b[i];
        if(n<=0) f0=true;
    }
    
    if(f0) cout << "No" << endl;
    else cout << "Yes" << endl;
}