/**
*    author:  shu8Cream
*    created: 21.02.2021 20:46:14
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
    ll a,b,c;
    cin >> a >> b >> c;
    int ans = 0;
    int d = a%10;
    int e2 = b%4;
    if(e2==1) e2=1;
    if(e2==2){
        if(c%4==1) e2=2;
        if(c%4==2) e2=4;
        if(c%4==3) e2=8;
        if(c%4==0) e2=6;
    }
    if(e2==3){
        if(c%4==1) e2=3;
        if(c%4==2) e2=9;
        if(c%4==3) e2=7;
        if(c%4==0) e2=1;
    }
    if(e2==0) e2=0;

    if(d==0 || d==1 || d==5 || d==6) ans=d;
    if(d==4){
        if(b%2==1) ans=4;
        else ans=6;
    }
    if(d==9){
        if(b%2==1) ans=9;
        else ans=1;
    }
    if(d==2){
        if(e2%4==1) ans=2;
        if(e2%4==2) ans=4;
        if(e2%4==3) ans=8;
        if(e2%4==0) ans=6;
    }
    if(d==3){
        if(e2%4==1) ans=3;
        if(e2%4==2) ans=9;
        if(e2%4==3) ans=7;
        if(e2%4==0) ans=1;
    }
    if(d==7){
        if(e2%4==1) ans=7;
        if(e2%4==2) ans=9;
        if(e2%4==3) ans=3;
        if(e2%4==0) ans=1;
    }
    if(d==8){
        if(e2%4==1) ans=8;
        if(e2%4==2) ans=4;
        if(e2%4==3) ans=2;
        if(e2%4==0) ans=6;
    }
    cout << ans << endl;
}