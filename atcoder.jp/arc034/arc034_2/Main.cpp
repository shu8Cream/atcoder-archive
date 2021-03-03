/**
*    author:  shu8Cream
*    created: 03.03.2021 21:39:23
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

ll f(ll x){
    ll res = 0;
    while(1){
        if(x<=0) break;
        res+=x%10;
        x/=10;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll k = 0;
    vector<ll> ans;
    for(ll i=1; i<163; i++){
        if(n-i>0 && i==f(n-i)){
            ans.push_back(n-i);
            k++;
        }
    }
    cout << k << endl;
    sort(all(ans));
    rep(i,ans.size()) cout << ans[i] << endl;
}