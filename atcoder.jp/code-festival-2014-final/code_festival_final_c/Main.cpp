/**
*    author:  shu8Cream
*    created: 16.02.2021 11:13:57
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
    ll a;
    cin >> a;
    vector<ll> n;
    for(ll i=10; i<20000; i++){
        ll j=i, e=1, t=j%10*e;
        while(j/=10){
            e *= i;
            t += j%10*e;
        }
        n.push_back(t);
    }
    rep(i,n.size()){
        if(n[i]==a){
            cout << i+10 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}