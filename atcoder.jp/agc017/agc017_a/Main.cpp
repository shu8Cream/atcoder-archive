/**
*    author:  shu8Cream
*    created: 02.03.2021 15:44:54
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,p;
    cin >> n >> p;
    vi a(n);
    int odd = 0, even = 0;
    rep(i,n){
        cin >> a[i];
        if(a[i]%2==0) even++;
        else odd++;
    }
    ll ans = 0, evall = 1LL<<even, tmp = 1;

    for(int i=0; i<=odd; i+=2){
        tmp=1;
        rep(j,i){
            tmp*=odd-j;
            tmp/=j+1;
        }
        ans+=tmp*evall;
    }
    if(p==1) ans=(1LL<<n) - ans;
    cout << ans << endl;
}