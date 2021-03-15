/**
*    author:  shu8Cream
*    created: 15.03.2021 10:53:51
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
    ll k,a,b,kk;
    cin >> k >> a >> b;
    kk=k;
    ll ans = 1;
    if(a>=b) ans+=k;
    else{
        k-=a-1;
        ans+=a-1;
        ans+=k/2*(b-a);
        k%=2;
        ans+=k;
    }
    ans = max(ans, kk+1);
    cout << ans << endl;
}