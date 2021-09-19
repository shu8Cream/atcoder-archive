/**
*    author:  shu8Cream
*    created: 19.09.2021 21:55:25
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

ll solve(){
    ll n2,n3,n4; cin >> n2 >> n3 >> n4;
    ll res = 0;
    vector<map<ll,ll>> vm(5);
    vm[0][2]=5;
    vm[1][2]=3;
    vm[1][4]=1;
    vm[2][2]=2;
    vm[2][3]=2;
    vm[3][2]=1;
    vm[3][4]=2;
    vm[4][3]=2;
    vm[4][4]=1;
    do{
        ll t2 = n2, t3 = n3, t4 = n4;
        ll ans = 0;
        rep(i,5){
            ll tmp = 8e18;
            for(auto [k,v] : vm[i]){
                if(k==2) chmin(tmp, t2/v);
                if(k==3) chmin(tmp, t3/v);
                if(k==4) chmin(tmp, t4/v);
            }
            ans += tmp;
            for(auto [k,v] : vm[i]){
                if(k==2) t2-=tmp*v;
                if(k==3) t3-=tmp*v;
                if(k==4) t4-=tmp*v;
            }
        }
        chmax(res,ans);
    }while(next_permutation(all(vm)));
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    rep(i,t) cout << solve() << endl;
}