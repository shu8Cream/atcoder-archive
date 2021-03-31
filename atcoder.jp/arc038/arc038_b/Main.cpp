/**
*    author:  shu8Cream
*    created: 31.03.2021 20:35:14
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int h,w;
vector<string> s;
int memo[110][110];
bool dfs(int i, int j){
    if(memo[i][j]!=0) return memo[i][j];
    if(i<0 || i>=h || j<0 || j>=w) return memo[i][j]=1;
    if(s[i][j]=='#') return memo[i][j]=1;
    if(dfs(i,j+1)==0) return memo[i][j]=1;
    if(dfs(i+1,j)==0) return memo[i][j]=1;
    if(dfs(i+1,j+1)==0) return memo[i][j]=1;
    return memo[i][j]=0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    s.resize(h);
    rep(i,h) cin >> s[i];
    cout << (dfs(0,0) ? "First" : "Second") << endl;
}