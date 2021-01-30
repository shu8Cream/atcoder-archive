/**
*    author:  shu8Cream
*    created: 30.01.2021 17:15:04
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<P> r(n),b(n);
    rep(i,n){
        int x,y; cin >> x >> y;
        r[i]={x,y};
    }
    rep(i,n){
        int x,y; cin >> x >> y;
        b[i]={y,x};
    }
    sort(rall(r));
    sort(all(b));
    vi used(n);
    int ans = 0;
    rep(i,n)rep(j,n){
        if(used[j]!=0) continue;
        int rx,ry,bx,by;
        tie(rx,ry)=r[i];
        tie(by,bx)=b[j];
        if(rx<bx && ry<by){
            ans++; used[j]=1;
            break;
        }
    }
    cout << ans << endl;
}