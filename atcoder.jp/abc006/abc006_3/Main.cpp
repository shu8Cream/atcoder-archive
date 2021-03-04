/**
*    author:  shu8Cream
*    created: 04.03.2021 11:23:01
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
    int n,m;
    cin >> n >> m;
    rep(x,n+1){
        if(0<=4*n-m-2*x && 4*n-m-2*x<=n){
            if(0<=-3*n+m+x && -3*n+m+x<=n){
                printf("%d %d %d\n", x,4*n-m-2*x,-3*n+m+x);
                return 0;
            }
        }
    }
    printf("%d %d %d\n", -1,-1,-1);
}