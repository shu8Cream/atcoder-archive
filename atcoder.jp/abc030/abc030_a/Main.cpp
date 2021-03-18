/**
*    author:  shu8Cream
*    created: 18.03.2021 17:42:15
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
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    if(b/a>d/c) cout << "TAKAHASHI" << endl;
    else if(b/a==d/c) cout << "DRAW" << endl;
    else cout << "AOKI" << endl;
}