/**
*    author:  shu8Cream
*    created: 19.12.2020 20:54:04
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    int n;
    cin >> n;
    set<int> se;
    rep(i,n){
        string s = to_string(i+1);
        rep(j,s.size()){
            if(s[j]=='7') se.insert(stoi(s));
        }
    }
    rep(i,n){
        int x=i+1;
        while(1){
            if(x==0) break;
            if(x%8==7) se.insert(i+1);
            x/=8;
        }
    }
    int ans = n-se.size();
    cout << ans << endl;
}