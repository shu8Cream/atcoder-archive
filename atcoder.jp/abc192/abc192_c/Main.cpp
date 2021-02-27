/**
*    author:  shu8Cream
*    created: 27.02.2021 15:19:03
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

ll g1(ll a){
    string s = to_string(a);
    vi b(s.size());
    rep(i,s.size()){
        b[i]=s[i]-'0';
    }
    sort(all(b));
    ll res = 0, tmp=1;
    for(auto p : b){
        res+=p*tmp;
        tmp*=10;
    }
    return res;
}

ll g2(ll a){
    string s = to_string(a);
    vi b(s.size());
    rep(i,s.size()){
        b[i]=s[i]-'0';
    }
    sort(all(b));
    reverse(all(b));
    ll res = 0, tmp=1;
    for(auto p : b){
        res+=p*tmp;
        tmp*=10;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    vector<ll> a(k+1);
    a[0]=n;
    rep(i,k){
        a[i+1]=g1(a[i])-g2(a[i]);
    }
    cout << a[k] << endl;
}