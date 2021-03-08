/**
*    author:  shu8Cream
*    created: 08.03.2021 22:16:09
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
    int n;
    cin >> n;
    vector<ll> a(n), ra(n+1), rra(n+1);
    rep(i,n) cin >> a[i];
    rep(i,n) ra[i+1]=a[i]+ra[i];
    rep(i,n+1) rra[i]=ra[i];
    //rep(i,n+1) cerr << ra[i] << endl;
    ll ans = 0, dt = 0;
    for(int i=1; i<=n;i++){
        if(i%2==1 && ra[i]<0){
            if(i!=n) ra[i+1]+=dt;
            continue;
        }
        if(i%2==0 && ra[i]>0){
            if(i!=n) ra[i+1]+=dt;
            continue;
        }
        if(i%2==1){
            ans+=ra[i]+1;
            dt+=-ra[i]-1;
            if(i!=n) ra[i+1]+=dt;
        }
        if(i%2==0){
            ans+=-ra[i]+1;
            dt+=-ra[i]+1;
            if(i!=n) ra[i+1]+=dt;
        }
    }
    ll tmp = 0; dt = 0;
    for(int i=1; i<=n;i++){
        if(i%2==1 && rra[i]>0){
            if(i!=n) rra[i+1]+=dt;
            continue;
        }
        if(i%2==0 && rra[i]<0){
            if(i!=n) rra[i+1]+=dt;
            continue;
        }
        if(i%2==1){
            tmp+=-rra[i]+1;
            dt+=-rra[i]+1;
            if(i!=n) rra[i+1]+=dt;
        }
        if(i%2==0){
            tmp+=rra[i]+1;
            dt+=-rra[i]-1;
            if(i!=n) rra[i+1]+=dt;
        }
    }
    cerr << ans << " " << tmp << endl;
    //rep(i,n+1) cerr << ra[i] << endl;
    ans=min(ans,tmp);
    cout << ans << endl;
}