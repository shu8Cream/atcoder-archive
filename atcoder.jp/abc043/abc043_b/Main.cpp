/**
*    author:  shu8Cream
*    created: 02.03.2021 11:31:47
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
    string ans="";
    rep(i,s.size()){
        if(s[i]=='0') ans+="0";
        if(s[i]=='1') ans+="1";
        if(s[i]=='B' && ans!="") ans.pop_back();
    }
    cout << ans << endl;
}