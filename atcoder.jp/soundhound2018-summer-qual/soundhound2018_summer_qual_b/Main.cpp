/**
*    author:  shu8Cream
*    created: 15.03.2021 15:00:08
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
    string s; int w;
    cin >> s >> w;
    string ans;
    rep(i,s.size()){
        if(i%w==0) ans+=s[i];
    }
    cout << ans << endl;
}