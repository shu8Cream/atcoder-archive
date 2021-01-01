/**
*    author:  shu8Cream
*    created: 31.12.2020 18:43:50
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

ll f(ll n){
    ll res=0;
    if(n>=1) res+=n;
    if(n>=2) res+=n*(n-1)*3;
    if(n>=3) res+=n*(n-1)*(n-2);
    return res;
}

int main() {
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    if(k%2==0){
        int cnt1 = n/k;
        int cnt2 = n/k;
        if(n/k*k+k/2<=n) cnt2++;
        ans=f(cnt1)+f(cnt2);
    }else{
        int cnt = n/k;
        ans=f(cnt);
    }
    cout << ans << endl;
}