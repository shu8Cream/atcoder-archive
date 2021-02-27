/**
*    author:  shu8Cream
*    created: 27.02.2021 15:18:53
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
    int n = s.size();
    bool ok = true;
    rep(i,n){
        if(i%2==0){
            if(0>s[i]-'a' || 25<s[i]-'a') ok = false;
        }else{
            if(0>s[i]-'A' || 25<s[i]-'A') ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}