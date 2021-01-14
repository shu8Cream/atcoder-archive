/**
*    author:  shu8Cream
*    created: 14.01.2021 14:38:37
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

    int n,m;
    cin >> n >> m;
    vvi s(m);
    rep(i,m){
        int k;
        cin >> k;
        rep(j,k){
            int a; cin >> a; a--;
            s[i].push_back(a);
        }
    }
    vi p(m);
    rep(i,m) cin >> p[i];

    ll ans = 0;
    rep(sc,1<<n){
        vi scnt(m);
        rep(i,n){
            rep(j,m){
                rep(k,s[j].size()){
                    if(sc>>i&1 && s[j][k]==i) scnt[j]++;
                }
            }
        }
        int cnt=0;
        rep(i,m){
            if(scnt[i]%2==p[i]) cnt++;
        }
        if(cnt==m) ans++;
    }
    cout << ans << endl;
}