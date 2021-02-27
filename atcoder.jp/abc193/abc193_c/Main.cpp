/**
*    author:  shu8Cream
*    created: 27.02.2021 20:11:01
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
    ll n;
    cin >> n;
    set<ll> s;
    ll cnt = 0;
    for(ll i=2; i*i<=n; i++){
        for(ll j=2; pow(i,j)<=n; j++){
            s.insert(pow(i,j));
        }
    }
    cout << n-s.size() << endl;
}