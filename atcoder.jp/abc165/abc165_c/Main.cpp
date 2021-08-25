#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) x.begin(), x.end()
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int n,m,q;
ll a[50],b[50],c[50],d[50];

ll dfs(vi &vec){
    if(vec.size()==n){
        ll res = 0;
        rep(i,q) if(vec[b[i]]-vec[a[i]]==c[i]) res+=d[i];
        return res;
    }
    ll ans = 0;
    int prevlast = (vec.empty() ? 1 : vec.back());
    for(int i = prevlast; i<=m; i++){
        vec.push_back(i);
        ans = max(ans,dfs(vec));
        vec.pop_back();
    }
    return ans;
}

int main(void){
    cin >> n >> m >> q;
    rep(i,q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }
    vi a;
    cout << dfs(a) << endl;
}
