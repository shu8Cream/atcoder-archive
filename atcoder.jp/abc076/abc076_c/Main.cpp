/**
*    author:  shu8Cream
*    created: 22.12.2020 21:29:07
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)

int main() {
    string s,t;
    cin >> s >> t;
    int keyitr=52;
    rep(i,s.size()-t.size()+1){
        int cnt=0;
        rep(j,t.size()){
            if(s[i+j]=='?') cnt++;
            if(s[i+j]==t[j]) cnt++;
            if(cnt==t.size()) keyitr=i;
        }
    }
    if(keyitr==52 || s.size()<t.size()){
        cout << "UNRESTORABLE" << endl;
    }else{
        string ans = s;
        rep(i,s.size()){
            if(i<keyitr && ans[i]=='?') ans[i]='a';
            if(i==keyitr) rep(k,t.size()) ans[i+k]=t[k];
            if(i>keyitr && ans[i]=='?') ans[i]='a'; 
        }
        cout << ans << endl;
    }
}