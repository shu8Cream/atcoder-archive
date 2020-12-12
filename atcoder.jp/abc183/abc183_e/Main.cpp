#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

const int INF = -1e9;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int mod = 1e9+7;

int dp[2020][2020];
int x[2020][2020];
int y[2020][2020];
int xy[2020][2020];

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    dp[0][0]=1;

    rep(i,h)rep(j,w){
        if(i==0 && j==0) continue;
        if(s[i][j]=='#') continue;
        if(j) x[i][j]=(x[i][j-1]+dp[i][j-1])%mod;
        if(i) y[i][j]=(y[i-1][j]+dp[i-1][j])%mod;
        if(i&&j) xy[i][j]=(xy[i-1][j-1]+dp[i-1][j-1])%mod;
        dp[i][j]=((x[i][j]+y[i][j])%mod+xy[i][j])%mod;
    }
    cout << dp[h-1][w-1]%mod << endl;
}