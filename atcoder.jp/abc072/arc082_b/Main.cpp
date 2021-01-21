/**
*    author:  shu8Cream
*    created: 21.01.2021 19:35:53
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
    vi p(n);
    rep(i,n) cin >> p[i];
    int ans = 0;
    rep(i,n){
        if(p[i]!=i+1) continue;
        else if(p[i+1]==i+2){
            ans++;
            i++;
        }else ans++;
    }
    cout << ans << endl;
}