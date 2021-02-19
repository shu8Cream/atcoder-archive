/**
*    author:  shu8Cream
*    created: 19.02.2021 12:38:25
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
    vi a(n), even(n);
    rep(i,n){
        cin >> a[i];
        if(a[i]%2==0) even[i]++;
        if(a[i]%4==0) even[i]++;
    }
    int four=0, eight=0;
    rep(i,n){
        if(even[i]==2) eight++;
        if(even[i]==1) four++;
    }
    bool ok = false;
    if(eight>=n-eight-four) ok=true;
    if(four==0 && eight+1>=n-eight-four) ok=true;
    cout << (ok ? "Yes" : "No") << endl;
}