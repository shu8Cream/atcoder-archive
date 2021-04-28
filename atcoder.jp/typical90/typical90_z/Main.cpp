/**
*    author:  shu8Cream
*    created: 28.04.2021 21:11:36
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vvi to(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vi dist(n,-1);
    queue<int> q;
    dist[0]=0;
    q.push(0);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto nv : to[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v]+1;
            q.push(nv); 
        }
    }
    int cnt = n/2, even = 0, odd = 0;
    rep(i,n){
        if(dist[i]%2==0) even++;
        else odd++;
    }
    if(even>=odd){
        rep(i,n) if(dist[i]%2==0 && cnt){
            cout << i+1 << endl;
            cnt--;
        }
    }else{
        rep(i,n) if(dist[i]%2==1 && cnt){
            cout << i+1 << endl;
            cnt--;
        }
    }
}