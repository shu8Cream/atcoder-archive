/**
*    author:  shu8Cream
*    created: 08.05.2021 14:54:16
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
    int n,k;
    cin >> n >> k;
    vector<int> a(n); rep(i,n) cin >> a[i];
    map<int,int> m;
    deque<int> dq;
    int ans = 0;
    rep(i,n){
        dq.push_back(a[i]);
        m[a[i]]++;
        while(m.size()>k){
            int v = dq.front();
            dq.pop_front();
            if(m[v]==1) m.erase(v);
            else m[v]--;
        }
        ans = max(ans, (int)dq.size());
    }
    cout << ans << endl;
}