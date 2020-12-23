/**
*    author:  shu8Cream
*    created: 23.12.2020 20:09:40
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using vi = vector<int>;

int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    int sum=0, cnt=0;
    rep(i,n){
        if(a[i]!=0){
            sum+=a[i];
            cnt++;
        }
    }
    int ans = (sum+cnt-1)/cnt;
    cout << ans << endl;
}