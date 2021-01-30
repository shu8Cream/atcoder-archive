/**
*    author:  shu8Cream
*    created: 30.01.2021 20:42:13
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> div = divisor(n);
    set<ll> s;
    ll ans = 0;
    rep(i,div.size()) s.insert(div[i]);

    for(auto p : s){
        if(p%2==1) ans++;
    }
    /*for(ll i=1; i*i<=n; i++){
        if(n%i==0 && ((n/i)%2)==1) ans++;
        else if(n%i==0 && i%2==1) ans++;
    }*/
    ans*=2;
    //if(n!=1 && n%2==1) ans+=2;
    cout << ans << endl;
}