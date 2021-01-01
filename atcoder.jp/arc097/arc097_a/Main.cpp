/**
*    author:  shu8Cream
*    created: 01.01.2021 11:05:29
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    set<string> se;
    rep(i,n)rep(j,k){
        if(i+j+1>n)continue; 
        se.insert(s.substr(i, j+1));
    }
    string ans;
    for(auto p : se){
        if(k==0) break;
        ans = p;
        k--;
    }
    cout << ans << endl;
}