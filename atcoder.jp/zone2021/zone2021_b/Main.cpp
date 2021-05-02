/**
*    author:  shu8Cream
*    created: 02.05.2021 10:37:54
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<double>;
using vvi = vector<vi>;

int n;
double D,H;

bool check(double mid, vi &d, vi & h){
    rep(i,n){
        if((h[i]-mid)*D>(H-mid)*d[i]) return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> D >> H;
    vi d(n),h(n);
    rep(i,n) cin >> d[i] >> h[i];
    double ok = 0.0, ng = 10000.0;
    int loop = 100;
    while(loop--){
        double mid = (ok + ng) / 2.0;
        if(check(mid,d,h)) ng = mid;
        else ok = mid; 
    }
    printf("%.10lf\n", ok);
}