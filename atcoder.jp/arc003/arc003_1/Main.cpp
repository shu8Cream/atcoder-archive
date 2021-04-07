/**
*    author:  shu8Cream
*    created: 07.04.2021 23:17:29
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
    int n; string s;
    cin >> n >> s;
    double ans = 0;
    rep(i,n){
        if(s[i]=='A') ans+=4.0;
        if(s[i]=='B') ans+=3.0;
        if(s[i]=='C') ans+=2.0;
        if(s[i]=='D') ans+=1.0;
    }
    printf("%.15lf\n", ans/n);
}