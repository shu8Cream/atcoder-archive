/**
*    author:  shu8Cream
*    created: 16.02.2021 11:38:55
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
    getline(cin, s);
    set<string> se;
    string ans;
    bool at = false; 
    rep(i,s.size()){
        if(s[i]=='@'){
            at=true;
            if(ans!="") se.insert(ans);
            ans="";
            continue;
        }
        if(s[i]==' '){
            at=false;
            if(ans!="") se.insert(ans);
            ans="";
        }
        if(at) ans+=s[i];
    }
    if(ans!="") se.insert(ans);
    for(auto p : se) cout << p << endl;
}