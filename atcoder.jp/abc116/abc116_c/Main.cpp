/**
*    author:  shu8Cream
*    created: 13.12.2020 12:29:43
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
    int n;
    cin >> n;
    vi h(n);
    rep(i,n) cin >> h[i];
    ll ans = 0;
    while(1){
        int sum=0;
        rep(i,n) sum+=h[i];
        if(sum==0) break;
        bool f=false;
        rep(i,n){
            if(i!=n-1 && h[i]!=0 && h[i+1]==0) f=true;
            if(i!=n-1 && f && h[i]==0 && h[i+1]!=0) {f=false; ans++;}
            if(h[i]==0) continue;
            else h[i]--;
        }
        //rep(i,n) cout << h[i] << " ";
        //cout << ans << endl;
        ans++;
    }

    cout << ans << endl;
}