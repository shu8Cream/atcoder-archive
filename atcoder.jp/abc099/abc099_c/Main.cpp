/**
*    author:  shu8Cream
*    created: 09.02.2021 15:33:42
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int MAX_N = 110000;

int memo[MAX_N];
int solve(int n){
    if(n==0) return 0;
    if(memo[n]!=-1) return memo[n];
    int res = n;
    for(int six=1; six<=n; six*=6) res = min(res, solve(n-six)+1);
    for(int nine=1; nine<=n; nine*=9) res = min(res, solve(n-nine)+1);
    return memo[n] = res;
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    rep(i,MAX_N) memo[i] = -1;
    cout << solve(n) << endl;
}