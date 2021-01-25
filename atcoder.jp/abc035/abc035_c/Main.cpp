/**
*    author:  shu8Cream
*    created: 25.01.2021 11:35:56
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
    int n,q;
    cin >> n >> q;
    vi a(n);
    rep(i,q){
        int l,r;
        cin >> l >> r; l--;
        if(i%2==0){
            a[l]++;
            a[r]--;
        }else{
            a[l]--;
            a[r]++;
        }
    }
    vi ra(n+1);
    rep(i,n) ra[i+1]=ra[i]+a[i];
    rep(i,n){
        if(ra[i+1]%2==0) cout << 0;
        if(ra[i+1]%2!=0) cout << 1;
    }
    cout << endl;
}