/**
*    author:  shu8Cream
*    created: 25.03.2021 23:15:42
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
    rep(i,n) cin >> a[i];
    int ans = 0;
    int prev = 0;
    if(a[0]<a[1]) prev = 1;
    if(a[0]>a[1]) prev = 2;
    rep(i,n-1){
        if(a[i]<a[i+1] && prev==1) continue;
        if(a[i]>a[i+1] && prev==2) continue;
        if(a[i]==a[i+1]) continue;
        if(!prev && a[i]<a[i+1]) prev=1;
        if(!prev && a[i]>a[i+1]) prev=2;
        if(a[i]>a[i+1] && prev==1){
            ans++;
            prev=0;
        }
        if(a[i]<a[i+1] && prev==2){
            ans++;
            prev=0;
        }
    }
    ans++;
    cout << ans << endl;
}