/**
*    author:  shu8Cream
*    created: 02.03.2021 11:48:33
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
    ll ans = 0;
    char pre = s[0];
    ll t1 = 0, t2=0;
    rep(i,s.size()){
        if(i && s[i]=='<' && s[i-1]=='>'){
            if(t1<t2){
                ans+=t1*(t1-1)/2;
                ans+=t2*(t2+1)/2;
            }else{
                ans+=t1*(t1+1)/2;
                ans+=t2*(t2-1)/2;
            }
            t1=0; t2=0;
        }
        if(s[i]=='<') t1++;
        if(s[i]=='>') t2++;
    }
    if(t1<t2){
        ans+=t1*(t1-1)/2;
        ans+=t2*(t2+1)/2;
    }else{
        ans+=t1*(t1+1)/2;
        ans+=t2*(t2-1)/2;
    }
    cout << ans << endl;
}