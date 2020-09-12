#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll k;
    cin >> k;
    vector<ll> s(k);
    rep(i,k){
        if(i==0) s[i]=7%k;
        else s[i]=(s[i-1]*10+7)%k;
    }
    rep(i,k){
        if(s[i]==0) {
            cout<<i+1<<endl;return 0;
        }
    }
    cout<<"-1"<<endl;
}