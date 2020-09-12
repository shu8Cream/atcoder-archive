#include <bits/stdc++.h>
#define rep(i,n) for (int i=1; i<=(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n,m;
    cin >> n >> m;
    if(n-m!=0 && n-m!=-1 && n-m!=1) cout << 0 << endl;
    ll sn=1,sm=1;
    if(n-m==0) {
        rep(i,n) {
            sn*=i;
            ll b=pow(10,9);
            if(sn>pow(10,9)+7) sn=sn%(b+7);
        }
        rep(i,m) {
            sm*=i;
            ll b=pow(10,9);
            if(sm>pow(10,9)+7) sm=sm%(b+7);
        }
        ll a=2*sn*sm;
        ll b=pow(10,9);
        if(a>pow(10,9)+7) a=a%(b+7);
        cout << a << endl;
        //2*n!*m!
    }
    if(n-m==1 || n-m==-1){
        rep(i,n) {
            sn*=i;
            ll b=pow(10,9);
            if(sn>pow(10,9)+7) sn=sn%(b+7);
        }
        rep(i,m) {
            sm*=i;
            ll b=pow(10,9);
            if(sm>pow(10,9)+7) sm=sm%(b+7);
        }
        ll a=sn*sm;
        ll b=pow(10,9);
        if(a>pow(10,9)+7) a=a%(b+7);
        cout << a << endl;
        //n!*m!
    }
}