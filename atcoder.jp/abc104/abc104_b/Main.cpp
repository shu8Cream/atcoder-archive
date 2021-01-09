/**
*    author:  shu8Cream
*    created: 09.01.2021 14:45:44
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
    string s;
    cin >> s;
    int n = s.size();
    bool f1 = false;
    if(s[0]=='A') f1= true;
    int cnt = 0;
    for(int i=2; i<=n-2; i++){
        if(s[i]=='C') cnt++;
    }
    bool f2 = false;
    if(cnt==1) f2 = true;
    cnt=0;
    rep(i,n){
        int d = s[i]-'a';
        if(d>=0 && d<=26) cnt++;
    }
    string ans = "WA";
    if(cnt==n-2 && f1 && f2) ans="AC";
    cout << ans << endl;
}