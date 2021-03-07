/**
*    author:  shu8Cream
*    created: 07.03.2021 21:17:43
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
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;        
        string ans(2*n+1,'1');
        rep(i,n) ans[i+n]='0';
        cout << ans << endl;
    }
}