/**
*    author:  shu8Cream
*    created: 26.01.2021 23:07:53
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

ll mod_pow(ll a, ll b, ll n){
    if(b==0) return 1;
    if(b%2!=0) return a * mod_pow(a, b-1, n) % n;
    else return mod_pow(a * a % n, b / 2, n) % n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n);
    bool ok = true;
    map<int,int> m;
    rep(i,n){
        cin >> a[i];
        if(n%2==a[i]%2) ok = false;
        m[a[i]]++;
    }
    int cnt=0;
    for(auto p : m){
        if(n%2==0){
            if(p.first!=cnt+1) ok=false;
            if(p.second!=2) ok=false;
        }else{
            if(p.first!=cnt) ok=false;
            if(cnt && p.second!=2) ok=false;
            if(!cnt && p.second!=1) ok=false; 
        }
        cnt+=2;
    }
    ll ans = 0;
    if(ok) ans = mod_pow(2, n/2, 1e9+7);
    cout << ans << endl;
}