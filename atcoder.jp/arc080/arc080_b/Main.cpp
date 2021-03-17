/**
*    author:  shu8Cream
*    created: 17.03.2021 17:26:15
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
    int h,w,n;
    cin >> h >> w >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    vvi ans(h,vi(w));
    rep(i,h){
        rep(j,w){
            rep(k,n){
                if(a[k]){
                    if(i%2==0) ans[i][j]=k+1;
                    else ans[i][w-j-1]=k+1;
                    a[k]--;
                    break;
                }
            }
        }
    }
    rep(i,h){
        cout << ans[i][0];
        rep(j,w-1) cout << " " << ans[i][j+1];
        cout << endl;
    }
}