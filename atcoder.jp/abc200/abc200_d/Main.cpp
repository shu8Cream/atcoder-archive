/**
*    author:  shu8Cream
*    created: 09.05.2021 21:03:30
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    vvi t(200);

    int cnt = min(n,8);
    rep(s,1<<cnt){
        if(!s) continue;
        vi b;
        int idx = 0;
        rep(i,cnt){
            if(s>>i&1){
                b.push_back(i+1);
                idx+=a[i];
                idx%=200;
            }
        }
        if(t[idx].size()!=0){
            cout << "Yes" << endl;
            cout << t[idx].size();
            for(auto p : t[idx]){
                cout << " " << p;
            }cout << endl;
            cout << b.size();
            for(auto p : b){
                cout << " " << p;
            }cout << endl;
            return 0;
        }else t[idx]=b;
    }
    cout << "No" << endl;
}