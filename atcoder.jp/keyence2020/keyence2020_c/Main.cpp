/**
*    author:  shu8Cream
*    created: 26.01.2021 00:45:51
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
    int n,k,s;
    cin >> n >> k >> s;
    vi a(n);
    rep(i,k) a[i]=s;
    rep(i,n-k){
        a[i+k]=s+1;
        if(s==1e9) a[i+k]=s-1;
    }
    rep(i,n){
        if(!i) cout << a[i];
        else cout << " " << a[i];
    }
    cout << endl;
}