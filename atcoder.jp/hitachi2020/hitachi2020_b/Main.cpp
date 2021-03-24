/**
*    author:  shu8Cream
*    created: 24.03.2021 09:46:26
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
    int a,b,m;
    cin >> a >> b >> m;
    vi aa(a),bb(b);
    int ma=1e9,mb=1e9;
    rep(i,a){
        cin >> aa[i];
        ma = min(ma,aa[i]);
    }
    rep(i,b){
        cin >> bb[i];
        mb = min(mb,bb[i]);
    }
    int ans = ma + mb;
    rep(i,m){
        int x,y,c;
        cin >> x >> y >> c;
        x--; y--;
        ans = min(ans, aa[x]+bb[y]-c);
    }
    cout << ans << endl;
}