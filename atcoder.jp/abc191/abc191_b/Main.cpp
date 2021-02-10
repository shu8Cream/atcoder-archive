/**
*    author:  shu8Cream
*    created: 10.02.2021 14:49:24
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
    int n,x;
    cin >> n >> x;
    vi a(n);
    rep(i,n) cin >> a[i];
    rep(i,n){
        if(a[i]!=x) cout << a[i] << endl;
    }
}