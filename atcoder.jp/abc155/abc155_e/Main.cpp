/**
*    author:  shu8Cream
*    created: 11.03.2021 10:30:56
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
    string n;
    cin >> n;
    int len = n.size();
    int dp[1000005][2];
    dp[0][1]=1;
    rep(i,len){
        int p = n[i]-'0';
        dp[i+1][0] = min(dp[i][0]+p, dp[i][1]+10-p);
        dp[i+1][1] = min(dp[i][0]+p+1, dp[i][1]+10-p-1);
    }
    cout << dp[len][0] << endl;
}