/**
*    author:  shu8Cream
*    created: 17.04.2021 15:46:16
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    int c = b-a;
    int ans = 0;
    for(int i=c; i>=1; i--){
        if((a+i-1)/i < b/i){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}