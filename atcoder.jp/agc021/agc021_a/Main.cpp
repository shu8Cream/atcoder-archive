/**
*    author:  shu8Cream
*    created: 04.03.2021 18:36:25
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

ll f(ll x){
    ll res = 0;
    while(1){
        if(x==0) break;
        res+=x%10;
        x/=10;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll nn = n;
    ll ans = 0, tmp = 0;
    while(n/=10){
        ans++;
        if(n!=0) tmp=n%10;
    }
    ans*=9;
    ans+=tmp-1;
    ans=max(ans,f(nn));
    cout << ans << endl;
}