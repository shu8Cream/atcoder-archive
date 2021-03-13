/**
*    author:  shu8Cream
*    created: 13.03.2021 20:32:19
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
    ll n, nn;
    cin >> n;
    nn=n;
    int keta = 1;
    while(nn/=10) keta++;
    ll ans = 0;
    /*if(keta>=4) ans += n-1000+1;
    if(keta>=10) ans += (n-1000000+1)*2;
    if(keta>=13) ans += (n-1000000000+1)*3;*/
    if(keta>=16){
        ans += (n-1000000000000000+1)*5;
        n=999999999999999;
    }
    //cerr << ans << endl;
    if(keta>=13){
        ans += (n-1000000000000+1)*4;
        n=999999999999;
    }
    //cerr << ans << endl;
    if(keta>=10){
        ans += (n-1000000000+1)*3;
        n=999999999;
    }
    //cerr << ans << endl;
    if(keta>=7){
        ans += (n-1000000+1)*2;
        n=999999;
    }
    //cerr << ans << endl;
    if(keta>=4){
        ans += n-1000+1;
        n=999;
    }
    cout << ans << endl;
}