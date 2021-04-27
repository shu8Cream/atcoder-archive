/**
*    author:  shu8Cream
*    created: 26.04.2021 20:55:22
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

const ll INF = 1LL<<60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    vi p(n),c(n);
    rep(i,n) {cin >> p[i]; p[i]--;}
    rep(i,n) cin >> c[i];

    vvi cycles;
    vi used(n);
    rep(i,n){
        if(used[i]) continue;
        vi cycle;
        int cur = i;
        while(!used[cur]){
            used[cur]=1;
            cycle.push_back(c[cur]);
            cur=p[cur];
        }
        cycles.push_back(cycle);
    }

    ll ans = -INF;
    for(auto cycle : cycles){
        ll len = cycle.size();
        vi rui(len * 2+1);
        rep(i,len*2) rui[i+1]=rui[i]+cycle[i%len];

        vi sum(len,-INF);
        rep(i,len){
            rep(j,len){
                sum[j]=max(sum[j],rui[i+j]-rui[i]);
            }
        }

        rep(i,len){
            if(i>k) continue;
            ll q = (k-i)/len;
            if(i==0 && q==0) continue;

            if(rui[len]>0) ans = max(ans, sum[i]+rui[len]*q);
            else if(i>0) ans = max(ans, sum[i]);
        }
    }
    cout << ans << endl;
}