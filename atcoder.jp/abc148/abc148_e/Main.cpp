/**
*    author:  shu8Cream
*    created: 02.03.2021 14:38:19
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
    ll n;
    cin >> n;
    ll ans = 0;
    if(n%2==1){
        cout << 0 << endl;
        return 0;
    }
    n/=2;
    while(n){
        ans+=n/5;
        n/=5;
    }
    cout << ans << endl;
}