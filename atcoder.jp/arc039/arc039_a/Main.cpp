/**
*    author:  shu8Cream
*    created: 04.04.2021 15:43:28
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
    int a,b;
    cin >> a >> b;
    int ans = -1e9;
    string s = to_string(a);
    string t = to_string(b);
    rep(i,3)rep(j,10){
        if(!i && !j) continue;
        string ss = s;
        ss[i]='0'+j;
        ans=max(ans,stoi(ss)-b);
    }
    rep(i,3)rep(j,10){
        if(!i && !j) continue;
        string tt = t;
        tt[i]='0'+j;
        ans=max(ans,a-stoi(tt));
    }
    cout << ans << endl;
}