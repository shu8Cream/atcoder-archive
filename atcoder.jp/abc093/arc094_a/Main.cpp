/**
*    author:  shu8Cream
*    created: 20.12.2020 17:27:48
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    vi a(3);
    rep(i,3) cin >> a[i];
    sort(a.begin(), a.end());
    int ans=a[2]-a[1];
    a[0]+=ans;
    ans+=(a[2]-a[0]+1)/2;
    if((a[2]-a[0])%2!=0) ans++;
    cout << ans << endl;
}