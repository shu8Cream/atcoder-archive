/**
*    author:  shu8Cream
*    created: 06.04.2021 20:40:42
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
    int ans = 0;
    rep(i,4){
        if(s[i]=='+') ans++;
        else ans--;
    }
    cout << ans << endl;
}