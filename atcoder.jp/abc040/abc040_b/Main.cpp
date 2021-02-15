/**
*    author:  shu8Cream
*    created: 15.02.2021 16:34:38
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
    int ans = 1e9;
    for(int i=1; i*i<=n; i++){
        for(int j=n/i; j>=i; j--){
            ans=min(ans, abs(i-j)+n-i*j);
        }
    }
    cout << ans << endl;
}