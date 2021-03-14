/**
*    author:  shu8Cream
*    created: 14.03.2021 13:36:55
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
    double a,b,w;
    cin >> a >> b >> w;
    int m = ceil(w*1000/b);
    int M = floor(w*1000/a);
    if(m>M) cout << "UNSATISFIABLE" << endl;
    else cout << m << " " << M << endl;
}