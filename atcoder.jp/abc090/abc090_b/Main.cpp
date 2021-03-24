/**
*    author:  shu8Cream
*    created: 24.03.2021 10:03:09
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
    int a,b;
    cin >> a >> b;
    int ans = 0;
    for(int i=a; i<=b; i++){
        string s = to_string(i), t=s;
        reverse(all(s));
        if(s==t) ans++;
    }
    cout << ans << endl;
}