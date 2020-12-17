/**
*    author:  shu8Cream
*    created: 17.12.2020 17:26:23
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
    int n,l;
    cin >> n >> l;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    sort(s.begin(), s.end());
    string ans;
    rep(i,n){
        ans+=s[i];
    }
    cout << ans << endl;
}