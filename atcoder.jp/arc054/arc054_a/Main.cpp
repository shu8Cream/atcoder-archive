/**
*    author:  shu8Cream
*    created: 01.03.2021 20:52:56
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
    double l,x,y,s,d;
    cin >> l >> x >> y >> s >> d;
    double ans = 1e9;
    if(s<d){
        ans=abs(s-d)/(x+y);
        if(y-x>0) ans=min(ans, abs(s+l-d)/(y-x));
    }else{
        if(y-x>0) ans=abs(s-d)/(y-x);
        ans=min(ans, abs(s-d-l)/(x+y));
    }
    printf("%.10lf\n", ans);
}