/**
*    author:  shu8Cream
*    created: 19.01.2021 14:18:51
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
    int n,h,w;
    cin >> n >> h >> w;
    int ans = 0;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        if(a>=h && b>=w) ans++;
    }
    cout << ans << endl;
}