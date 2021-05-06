/**
*    author:  shu8Cream
*    created: 09.04.2021 09:04:28
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<double,double>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<P> xy(n);
    rep(i,n){
        double x,y; cin >> x >> y;
        xy[i] = {x,y};
    }
    double ans = 0.0;
    // B select
    rep(i,n){
        vector<double> hen;
        rep(j,n){
            if(i==j) continue;
            double ax,ay,bx,by;
            tie(ax,ay) = xy[j];
            tie(bx,by) = xy[i];
            double angle = atan2(ay-by,ax-bx) * 180.0 / M_PI;
            hen.push_back(angle);
        }
        sort(all(hen));
        double res = 0.0;
        int m = hen.size();
        rep(j,m){
            double tar = hen[j] + 180.0;
            if(tar >= 360.0) tar -= 360.0;
            int pos = lower_bound(all(hen), tar) - hen.begin();
            int cand1 = pos % m;
            int cand2 = (pos+m-1) % m;
            double c1 = abs(hen[j] - hen[cand1]);
            double c2 = abs(hen[j] - hen[cand2]);
            if(c1>=180.0) c1 = 360.0 - c1;
            if(c2>=180.0) c2 = 360.0 - c2;
            res = max({res, c1, c2});
        }
        ans = max(ans, res);
    }
    
    printf("%.15lf\n",ans);
}

