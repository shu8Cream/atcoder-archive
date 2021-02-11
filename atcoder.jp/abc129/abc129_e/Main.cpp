/**
*    author:  shu8Cream
*    created: 11.02.2021 20:11:22
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int mod = 1e9+7;

ll mod_pow(ll a, ll b, ll n){
    if(b==0) return 1;
    if(b%2!=0) return a * mod_pow(a, b-1, n) % n;
    else return mod_pow(a * a % n, b / 2, n) % n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string l;
    cin >> l;
    int n = l.size();
    ll ans = 0, tmp = 1;
    rep(i,n){
        if(l[i]=='1'){
            ans+=tmp*mod_pow(3,(n-i-1),mod);
            ans%=mod;
            tmp=tmp*2%mod;
        }
    }
    ans=(ans+tmp)%mod;
    cout << ans << endl;
}