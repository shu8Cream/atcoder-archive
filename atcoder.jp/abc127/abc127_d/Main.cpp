/**
*    author:  shu8Cream
*    created: 28.12.2020 00:55:46
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
    int n,m;
    cin >> n >> m;
    vector<P> vp;
    rep(i,n){
        int a;
        cin >> a;
        vp.push_back({a,1});
    }
    rep(i,m){
        int b,c;
        cin >> b >> c;
        vp.push_back({c,b});
    }
    sort(all(vp));
    reverse(all(vp));
    ll ans = 0;
    int cnt = 0;
    for(auto p :vp){
        if(cnt + p.second <= n){
            ans+=(ll)p.first*p.second;
            cnt+=p.second;
        }else{
            ans+=(ll)p.first*(n-cnt);
            cnt=n;
            break;
        }
    }
    cout << ans << endl;
}