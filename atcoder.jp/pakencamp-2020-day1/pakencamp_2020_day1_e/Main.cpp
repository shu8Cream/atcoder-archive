/**
*    author:  shu8Cream
*    created: 08.01.2021 11:03:58
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
    ll x,y;
    cin >> x >> y;
    if(x==0 && y==0) cout << 1 << " " << 1 << endl;
    else if(x==y) cout << -1 << endl;
    else if(x<y) cout << x+2*y << " " << y << endl;
    else if(x>y) cout << x << " " << 2*x+y << endl;
}