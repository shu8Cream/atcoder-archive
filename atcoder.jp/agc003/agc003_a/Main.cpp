/**
*    author:  shu8Cream
*    created: 02.03.2021 13:54:34
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
    int n=0,ss=0,w=0,e=0;
    rep(i,s.size()){
        if(s[i]=='N') n++;
        if(s[i]=='W') w++;
        if(s[i]=='E') e++;
        if(s[i]=='S') ss++;
    }
    bool ok = true;
    if(n&&!ss || !n&&ss) ok=false;
    if(e&&!w || !e&&w) ok=false;
    cout << (ok ? "Yes" : "No") << endl;
}