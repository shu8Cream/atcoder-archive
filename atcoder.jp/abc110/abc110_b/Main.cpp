/**
*    author:  shu8Cream
*    created: 03.02.2021 11:04:19
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vi xx(n),yy(m);
    rep(i,n) cin >> xx[i];
    rep(i,m) cin >> yy[i];
    sort(rall(xx));
    sort(all(yy));
    bool ok = false;
    for(int i=xx[0]+1; i<=yy[0]; i++){
        if(x<i && i<=y){
            ok=true;
            break;
        }
    }
    cout << (ok ?  "No War" : "War") << endl;
}