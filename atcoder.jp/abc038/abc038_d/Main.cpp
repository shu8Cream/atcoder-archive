/**
*    author:  shu8Cream
*    created: 03.04.2021 17:39:04
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int INF = 1001001001;

int LIS(const vector<P> &a){
    int n = a.size();
    vi dp(n, INF);
    rep(i,n){
        auto itr = lower_bound(all(dp),a[i].second);
        * itr = a[i].second;
    }
    return lower_bound(all(dp), INF) - dp.begin();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<P> hw(n);
    rep(i,n){
        int h,w; cin >> h >> w;
        hw[i]={h,w};
    }
    sort(all(hw), [](P a, P b){return a.first*1e6-a.second<b.first*1e6-b.second;});
    cout << LIS(hw) << endl;
}