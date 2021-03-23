/**
*    author:  shu8Cream
*    created: 23.03.2021 19:22:07
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
    int a,b; string s;
    cin >> a >> b >> s;
    bool ok = true;
    rep(i,a+b+1){
        if(0<=i && i<a){
            if(0<=s[i]-'0' && s[i]-'0'<=9) continue;
            else ok = false;
        } 
        if(s[a]!='-') ok = false;
        if(a+1<=i && i<a+b+1){
            if(0<=s[i]-'0' && s[i]-'0'<=9) continue;
            else ok = false;
        } 
    }
    cout << (ok ? "Yes" : "No") << endl;
}