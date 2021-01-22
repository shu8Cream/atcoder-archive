/**
*    author:  shu8Cream
*    created: 21.01.2021 23:03:43
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,a,b,c,d; string s; 
    cin >> n >> a >> b >> c >> d >> s;
    
    bool ok = true;
    for (int i=a; i<c-1; i++){
        if (s[i]=='#' && s[i+1]=='#') ok = false;
    }
    for (int i=b; i<d-1; i++){
        if (s[i]=='#' && s[i+1]=='#') ok = false;
    }
    bool f = false;
    if (c > d){
        for (int i=b-1; i<d; i++){
        if (s[i-1]=='.' && s[i]=='.' && s[i+1]=='.') f = true;
        }
    }
    else f = true;
    
    cout << ((ok && f) ? "Yes" : "No")<< endl;
}