/**
*    author:  shu8Cream
*    created: 04.03.2021 21:30:10
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
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    rep(x,n+1){
        for(int y=0; y<(n-r*x)+1; y++){
            if(n-r*x-g*y<0) continue;
            if((n-r*x-g*y)%b==0) ans++;
        }
    }
    cout << ans << endl;
}