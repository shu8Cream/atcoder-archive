/**
*    author:  shu8Cream
*    created: 14.03.2021 13:46:49
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
    int n,m,q;
    cin >> n >> m >> q;
    vector<P> wv(n), x(m);
    rep(i,n) cin >> wv[i].first >> wv[i].second;
    rep(i,m){
        cin >> x[i].first;
        x[i].second=i;
    }
    sort(all(x));
    sort(wv.rbegin(), wv.rend());
    rep(_,q){
        int l,r; cin >> l >> r; l--; r--;
        int ans = 0;
        vi used(n);
        rep(i,m){
            if(l<=x[i].second && x[i].second<=r) continue;
            int tmp = -1;
            rep(j,n){
                if(!used[j] && x[i].first>=wv[j].first){
                    if(tmp==-1 || wv[j].second>wv[tmp].second)
                        tmp=j;
                }
            }
            if(tmp==-1) continue;
            ans+=wv[tmp].second;
            used[tmp]=1;
        }
        cout << ans << endl;
    }
}