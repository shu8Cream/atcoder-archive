/**
*    author:  shu8Cream
*    created: 04.03.2021 11:20:43
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
    int n;
    cin >> n;
    vi a(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }
    int ans = 0;
    rep(i,n){
        if(i==a[a[i]]) ans++;
    }
    cout << ans/2 << endl;
}