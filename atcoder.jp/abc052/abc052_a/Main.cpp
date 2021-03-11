/**
*    author:  shu8Cream
*    created: 11.03.2021 23:58:56
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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << (a*b>c*d ? a*b : c*d) << endl;
}