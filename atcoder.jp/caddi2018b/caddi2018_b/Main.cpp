/**
*    author:  shu8Cream
*    created: 19.01.2021 14:19:06
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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    bool fi = false;
    rep(i,n){
        if(a[i]%2!=0) fi = true;
    }
    cout << (fi ? "first" : "second") << endl;
}