/**
*    author:  shu8Cream
*    created: 16.01.2021 20:55:04
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
    int n,k;
    cin >> n >> k;
    vi a(n);
    map<int,int> m;
    rep(i,n){
        cin >> a[i];
        m[a[i]]++;
    }
    ll ans = 0;
    rep(i,n){
        if(m.count(i)){
            if(k>m[i]){
                ans+=(k-m[i])*i;
                k=m[i];
            }
        }else{
            ans+=i*k;
            k=0;
        }
    }
    cout << ans << endl;
}