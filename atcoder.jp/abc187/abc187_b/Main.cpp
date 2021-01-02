/**
*    author:  shu8Cream
*    created: 02.01.2021 20:42:25
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
    int n;
    cin >> n;
    vector<double> x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    rep(i,n){
        for(int j=i+1; j<n; j++){
            if(-1<=(y[j]-y[i])/(x[j]-x[i]) && (y[j]-y[i])/(x[j]-x[i])<=1) ans++;
        }
    }
    cout << ans << endl;
}