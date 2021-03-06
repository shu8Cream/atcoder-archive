/**
*    author:  shu8Cream
*    created: 06.03.2021 20:47:56
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (double i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    double n;
    cin >> n;
    double ans = 0;
    rep(i,n-1){
        ans+=1/(i+1);
    }
    ans*=n;
    printf("%.10lf\n", ans);
}