/**
*    author:  shu8Cream
*    created: 02.03.2021 20:52:52
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
    if(n<2) cout << 1 << endl;
    else if(n<4) cout << 2 << endl;
    else if(n<8) cout << 4 << endl;
    else if(n<16) cout << 8 << endl;
    else if(n<32) cout << 16 << endl;
    else if(n<64) cout << 32 << endl;
    else cout << 64 << endl;
}