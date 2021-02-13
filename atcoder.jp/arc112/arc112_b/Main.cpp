/**
*    author:  shu8Cream
*    created: 13.02.2021 20:47:53
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
    ll b,c;
    cin >> b >> c;
    ll ans = 0;
    ll l=-b-(c-1)/2, r=-b+(c-1)/2;
    ll p=b-c/2, q=b+(c-2)/2;

    if(q<l) ans+=q-p+1 + r-l+1;
    else if(r<p) ans+=q-p+1 + r-l+1;
    else if(p<=l && l<=q) ans+=r-p+1;
    else if(p<=r && r<=q) ans+=q-l+1;
    else if(p<=l && r<=q) ans+=q-p+1;
    else if(l<=p && q<=r) ans+=r-l+1;
    cout << ans << endl;
}