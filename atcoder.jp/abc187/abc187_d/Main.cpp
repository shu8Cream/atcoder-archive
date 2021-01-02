/**
*    author:  shu8Cream
*    created: 02.01.2021 20:47:22
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
    int n;
    cin >> n;
    vector<tuple<ll, ll, ll>> ab(n);
    ll sum=0,suma=0, sumb=0;
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        ab[i] = {2*a+b, a, b};
        sum+=a+b;
        suma+=a;
    }
    sort(ab.rbegin(), ab.rend());
    int ans = 0;
    rep(i,n){
        ll c,a,b;
        tie(c,a,b) = ab[i];
        //printf("%d %d %d %d\n", sum,a+b,a,b);
        suma-=a;
        sumb+=a+b;
        ans++;
        //cout << sum << endl;
        if(suma<sumb) break;
    }
    cout << ans << endl;
}