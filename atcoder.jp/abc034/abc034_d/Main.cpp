/**
*    author:  shu8Cream
*    created: 11.04.2021 18:25:35
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;

bool check(vector<P> wp, double mid, int k){
    int n = wp.size();
    vector<double> p(n);
    rep(i,n) p[i]=wp[i].first*(wp[i].second-mid);
    sort(all(p));
    double res = 0;
    rep(i,k) res+=p[i];
    return res>=0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<P> wp(n);
    rep(i,n) cin >> wp[i].first >> wp[i].second;
    double ok = 0, ng = 100;
    rep(i,100){
        double mid = (ok + ng) / 2.0;
        if(check(wp,mid,k)) ok = mid;
        else ng = mid;
    }
    printf("%.15lf\n", ok);
}