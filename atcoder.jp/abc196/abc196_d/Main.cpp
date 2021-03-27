/**
*    author:  shu8Cream
*    created: 20.03.2021 20:48:55
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int h,w,a,b;
int used[16][16];

ll dfs(int i, int j, int a, int b){
    if(a<0 || b<0) return 0;
    if(j==w) j=0,i++;
    if(i==h) return 1;
    if(used[i][j]) return dfs(i,j+1,a,b);
    ll res = 0;
    used[i][j]=1;
    res+=dfs(i,j+1,a,b-1);
    if(j+1<w && !used[i][j+1]){
        used[i][j+1]=1;
        res+=dfs(i,j+1,a-1,b);
        used[i][j+1]=0;
    }
    if(i+1<h && !used[i+1][j]){
        used[i+1][j]=1;
        res+=dfs(i,j+1,a-1,b);
        used[i+1][j]=0;
    }
    used[i][j]=0;
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> h >> w >> a >> b;
    cout << dfs(0,0,a,b) << endl;
}