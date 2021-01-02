/**
*    author:  shu8Cream
*    created: 02.01.2021 20:42:51
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
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
        reverse(all(s[i]));
    }
    sort(all(s));
    string tmp="", ans="";
    rep(i,n){
        if(s[i][s[i].size()-1]!='!') tmp=s[i];
        if(tmp==s[i].substr(0,s[i].size()-1)) ans=tmp;
    }
    reverse(all(ans));
    if(ans=="") cout << "satisfiable" << endl;
    else cout << ans << endl;
}