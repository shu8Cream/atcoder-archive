/**
*    author:  shu8Cream
*    created: 12.02.2021 14:14:05
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
    int n,c;
    cin >> n >> c;
    vi a(n), e(10), o(10);
    rep(i,n){
        cin >> a[i];
        if(i%2==0) e[a[i]-1]++;
        else o[a[i]-1]++;
    }
    int ans = 0;
    rep(i,10)rep(j,10){
        if(i==j) continue;
        ans=max(ans, e[i]+o[j]);
    }
    cout << (n-ans)*c << endl;
}