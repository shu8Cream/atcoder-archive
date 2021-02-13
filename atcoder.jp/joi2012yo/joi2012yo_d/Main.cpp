/**
*    author:  shu8Cream
*    created: 13.02.2021 13:46:31
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int mod = 10000;

int c[110];
int dp[110][4][4];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    rep(i,k){
        int a,b;
        cin >> a >> b;
        //事前に決めたパスタを格納
        c[a-1]=b;
    }

    //DPテーブルの初期化
    if(c[0]!=0) dp[0][c[0]][0] = 1;
    else{
        dp[0][1][0] = 1;
        dp[0][2][0] = 1;
        dp[0][3][0] = 1;
    }

    //DP
    for(int i=1; i<n; i++){
        for(int j=1; j<=3; j++){
            for(int k=0; k<=3; k++){
                if(j==k && c[i]==j) continue;
                if(c[i]!=0) dp[i][c[i]][j] += dp[i-1][j][k]%mod;
                else{
                    rep(l,4){
                        if(j==k && k==l+1) continue;
                        dp[i][l+1][j]+=dp[i-1][j][k]%mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i,3)rep(j,4){
        ans+=dp[n-1][i+1][j];
        ans%=mod;
        //cout << dp[n-1][i+1][j] << endl;
    }
    cout << ans << endl;
}