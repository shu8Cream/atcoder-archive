/**
*    author:  shu8Cream
*    created: 13.04.2021 15:24:22
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
    int n,k; cin >> n >> k;
    vi x(n),y(n),xa(n),ya(n);
    rep(i,n){
        cin >> x[i] >> y[i];
        xa[i]=x[i]; ya[i]=y[i];
    }
    sort(all(xa)); sort(all(ya));
    ll ans = 8e18;
    rep(xi,n)for(int xj=xi+1; xj<n; xj++){
        rep(yi,n)for(int yj=yi+1; yj<n; yj++){
            int num = 0;
            ll lx = xa[xi], rx = xa[xj];
            ll by = ya[yi], uy = ya[yj];
            rep(i,n){
                if(lx<=x[i] && x[i]<=rx && by<=y[i] && y[i]<=uy) num++;
            }
            if(num>=k) ans = min(ans, (rx-lx)*(uy-by));
        }
    }
    cout << ans << endl;
}