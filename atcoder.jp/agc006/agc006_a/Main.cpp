/**
*    author:  shu8Cream
*    created: 03.03.2021 16:30:20
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
    int n; string s,t;
    cin >> n >> s >> t;
    int ans = 0;
    rep(i,n+1){
        if(s.substr(n-i,i)==t.substr(0,i)) ans=i+(n-i)*2;
    }
    cout << ans << endl;
}