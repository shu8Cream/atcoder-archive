/**
*    author:  shu8Cream
*    created: 02.01.2021 21:49:26
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vi to[200005];
vector<ll> cnt;
vi depth;

void depthDfs(int v, int d, int p=-1){
    depth[v]=d;
    for(int u : to[v]){
        if(u==p) continue;
        depthDfs(u,d+1,v);
    }
}
 
void imosDfs(int v, int p=-1) {
    for(int u : to[v]){
        if(u==p) continue;
        cnt[u]+=cnt[v];
        imosDfs(u,v);
    }
}
 
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n-1),b(n-1);
    rep(i,n-1){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        to[a[i]].push_back(b[i]);
        to[b[i]].push_back(a[i]);
    }
    cnt.resize(n);
    depth.resize(n);
    depthDfs(0,0);
    int q;
    cin >> q;
    rep(i,q){
        int t,e;
        ll x;
        cin >> t >> e >> x;
        e--;
        if(t==1){
            if(depth[a[e]]<depth[b[e]]){
                cnt[0]+=x;
                cnt[b[e]]-=x;
            }else cnt[a[e]]+=x;
        }else{
            if(depth[a[e]]<depth[b[e]]) cnt[b[e]]+=x;
            else{
                cnt[0]+=x;
                cnt[a[e]]-=x;
            }
        }
    }
    imosDfs(0);
    rep(i,n) cout << cnt[i] << endl;
}