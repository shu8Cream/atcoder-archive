/**
*    author:  shu8Cream
*    created: 27.03.2021 17:39:07
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
    int n,c,k;
    cin >> n >> c >> k;
    vi t(n);
    rep(i,n) cin >> t[i];
    sort(all(t));
    int ans = 0;
    int cur = 0;
    rep(i,n){
        if(t[i]-t[cur]>k || i-cur>=c){
            ans++;
            cur = i;
        }
    }
    ans++;
    cout << ans << endl;
}