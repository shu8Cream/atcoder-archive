/**
*    author:  shu8Cream
*    created: 09.04.2021 08:50:39
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
    vi a(n),b(n);
    rep(i,n){
        int c,p;
        cin >> c >> p;
        if(c==1) a[i]=p;
        else b[i]=p;
    }
    vi ar(n+1),br(n+1);
    rep(i,n) ar[i+1]=ar[i]+a[i];
    rep(i,n) br[i+1]=br[i]+b[i];
    int q; cin >> q;
    rep(i,q){
        int l,r; cin >> l >> r; 
        l--; r--;
        cout << ar[r+1]-ar[l] << " " << br[r+1]-br[l] << endl;
    }
}