/**
*    author:  shu8Cream
*    created: 23.02.2021 22:44:19
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
    int m,n,N;
    cin >> m >> n >> N;
    int ans = N;
    while(N/m>0){
        ans+=N/m*n;
        N=N/m*n+N%m;
    }
    cout << ans << endl;
}