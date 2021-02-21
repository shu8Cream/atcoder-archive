/**
*    author:  shu8Cream
*    created: 21.02.2021 20:46:03
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
    int k;
    cin >> k;
    ll ans = 0;
    for(int i=1; i*i*i<=k; i++){
        for(int j=i; i*j*j<=k; j++){
            for(int l=j; i*j*l<=k; l++){
                if(i*j*l<=k){
                    if(i==j && j==l) ans++;
                    else if(i==j || j==l || l==i) ans+=3;
                    else ans+=6;
                }
            }
        }
    }
    cout << ans << endl;
}