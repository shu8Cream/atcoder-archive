/**
*    author:  shu8Cream
*    created: 02.03.2021 22:12:48
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vvl xyz(n,vl(3));
    rep(i,n)rep(j,3) cin >> xyz[i][j];
    ll ans = 0;
    rep(b,1<<3){
        vl a;
        rep(i,n){
            ll tmp = 0;
            rep(j,3){
                if(b>>j&1){
                    tmp+=xyz[i][j];
                }else{
                    tmp-=xyz[i][j];
                }
            }
            a.push_back(tmp);
        }
        sort(all(a));
        ll sum = 0;
        rep(i,m){
            sum+=a[i];
        }
        ans=max(ans,sum);
    }
    cout << ans << endl;
}