/**
*    author:  shu8Cream
*    created: 10.04.2021 22:59:59
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
    ll n,x,m;
    cin >> n >> x >> m;
    vi r(m,-1),l;
    ll a = x, sum = 0;
    while(r[a]==-1){
        l.push_back(a);
        r[a]=l.size()-1;
        sum+=a;
        a=a*a%m;
    }
    int cyc = l.size()-r[a];
    ll T = 0;
    for(int i=r[a]; i<l.size(); i++) T+=l[i];
    ll ans = 0;
    if(n<=l.size()) rep(i,n) ans+=l[i];
    else{
        ans+=sum;
        n-=l.size();
        ans+=T*(n/cyc);
        n%=cyc;
        rep(i,n) ans+=l[r[a]+i];
    }

    cout << ans << endl;
}