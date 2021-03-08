/**
*    author:  shu8Cream
*    created: 07.03.2021 21:08:50
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    priority_queue<ll> pq;
    rep(i,n){
        int a; cin >> a;
        pq.push(a);
    }
    while(m--){
        ll p = pq.top();
        pq.pop();
        p/=2;
        pq.push(p);
    }
    ll ans = 0;
    while(!pq.empty()){
        ll p = pq.top();
        pq.pop();
        ans+=p;
    }
    cout << ans << endl;
}