/**
*    author:  shu8Cream
*    created: 22.05.2021 21:05:56
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

const int MAX = 30;
ll dp[MAX+1][MAX+1];

string find_kth(ll a, ll b, ll k){
    if(a==0) return string(b,'b');
    if(b==0) return string(a,'a');
    if(k<=dp[a-1][b]) return string("a") + find_kth(a-1,b,k);
    else return string("b") + find_kth(a,b-1,k-dp[a-1][b]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b,k;
    cin >> a >> b >> k;
    dp[0][0] = 1;
    rep(i,a+1)rep(j,b+1){
        if(i>0) dp[i][j]+=dp[i-1][j];
        if(j>0) dp[i][j]+=dp[i][j-1];
    }
    cout << find_kth(a,b,k) << endl;
}