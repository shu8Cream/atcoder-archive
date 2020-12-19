#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i=n-1, j=0; i>0; i-=2, j++){
        ans+=abs(a[j]-a[n-1-j])*i;
    }
    cout << ans << endl;
}