/**
*    author:  shu8Cream
*    created: 20.03.2021 20:48:42
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
    string x,ans="";
    cin >> x;
    int n = x.size();
    rep(i,n){
        if(x[i]=='.') break;
        ans+=x[i];
    }
    cout << ans << endl;
}