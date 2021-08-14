/**
*    author:  shu8Cream
*    created: 14.08.2021 13:55:08
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

int n;
vi t;

bool check(ll x, ll sum){
    rep(i,n){
        ll sum2 = 0;
        ll a = x;
        for(int j=i; j<n; j++){
            if(a-t[j]>=0){
                a-=t[j];
                sum2 += t[j];
            }
        }
        if(sum-sum2<=x) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    t.resize(n); rep(i,n) cin >> t[i];
    int sum = 0;
    rep(i,n) sum+=t[i];
    sort(rall(t));
    ll ok = sum, ng = -1;
    while(ok-ng>1){
        ll mid = (ok+ng)/2;
        if(check(mid,sum)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}