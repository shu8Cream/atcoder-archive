/**
*    author:  shu8Cream
*    created: 27.03.2021 20:56:32
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    ll ans = 5e18;
    rep(s,1<<(n-1)){
        vi tmp;
        ll c = a[0];
        rep(i,n-1){
            if(s>>i&1){
                tmp.push_back(c);
                c = a[i+1];
            }else{
                c|=a[i+1];
            }
        }
        tmp.push_back(c);
        ll res = 0;
        rep(i,tmp.size()){
            res^=tmp[i];
        }
        ans=min(ans,res);
    }
    cout << ans << endl;
}