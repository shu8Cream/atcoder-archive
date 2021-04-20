/**
*    author:  shu8Cream
*    created: 05.04.2021 20:08:39
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
    string s; int n,k;
    cin >> n >> k >> s;
    vvi c(n+5,vi(26));
    rep(i,26) c[n][i]=n;
    for(int i=n-1; i>=0; i--){
        rep(j,26){
            if(s[i]-'a'==j) c[i][j]=i;
            else c[i][j]=c[i+1][j];
        }
    }
    string ans = ""; int npos = 0;
    rep(i,k)rep(j,26){
        int nexpos = c[npos][j];
        int maxLen = n - nexpos  + i;
        if(maxLen>=k){
            ans+=(char)('a'+j);
            npos = nexpos+1;
            break;
        }
    }
    cout << ans << endl;
}