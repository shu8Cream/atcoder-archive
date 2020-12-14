/**
*    author:  shu8Cream
*    created: 14.12.2020 22:48:18
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
    double n,k;
    cin >> n >> k;
    
    double ans = (1+6*(k-1)*(n-k)+3*(n-1))/n/n/n;

    printf("%.12lf\n", ans);
}