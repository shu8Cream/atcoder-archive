/**
*    author:  shu8Cream
*    created: 13.03.2021 20:32:35
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
    int n; string s,x;
    cin >> n >> s >> x;
    
    vi dp(7);
    dp[0]=1;
    int ten = 1; 
    for(int i=n-1; i>=0; i--){
        vi old(7);
        swap(dp,old);
        rep(j,7){
            int nj = (j + ten*(s[i]-'0')) % 7;
            if(x[i]=='T') dp[j] = old[j] | old[nj];
            else dp[j] = old[j] & old[nj];
        }
        ten = (ten*10)%7;
    }
    if(dp[0]==1) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}