/**
*    author:  shu8Cream
*    created: 22.03.2021 23:06:24
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
    vi a(25);
    a[0]=100; a[1]=100; a[2]=200; 
    rep(i,20) a[i+3]=a[i]+a[i+1]+a[i+2];
    cout << a[19] << endl;
}