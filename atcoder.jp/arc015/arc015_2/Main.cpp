/**
*    author:  shu8Cream
*    created: 07.04.2021 23:10:41
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
    int n;
    cin >> n;
    int mousho = 0, manatsu = 0, natsu = 0;
    int nettai = 0, huyu = 0, mahuyu = 0;
    rep(i,n){
        double m,M;
        cin >> M >> m;
        if(M>=35) mousho++;
        else if(M>=30) manatsu++;
        else if(M>=25) natsu++;
        if(m>=25) nettai++;
        if(m<0 && M>=0) huyu++;
        if(M<0) mahuyu++;
    }
    printf("%d %d %d %d %d %d\n", mousho, manatsu, natsu, nettai, huyu, mahuyu);
}