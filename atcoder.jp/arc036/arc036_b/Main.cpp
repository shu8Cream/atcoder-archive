/**
*    author:  shu8Cream
*    created: 03.03.2021 21:33:36
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
    vi h(n);
    rep(i,n) cin >> h[i];
    int ans = 1, tmp = 1;
    bool up = 1;
    rep(i,n-1){
        if(h[i]<h[i+1]){
            if(up) tmp++;
            else{
                ans=max(ans,tmp);
                tmp=2; up=1;
            }
        }else{
            up=0;
            tmp++;
        }
        ans=max(ans,tmp);
    }
    cout << ans << endl;
}