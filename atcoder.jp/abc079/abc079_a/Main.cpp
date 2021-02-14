/**
*    author:  shu8Cream
*    created: 14.02.2021 23:59:06
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
    string n;
    cin >> n;
    bool ok = false;
    if(n[0]==n[1] && n[1]==n[2]) ok=true;
    if(n[2]==n[1] && n[3]==n[2]) ok=true;
    cout << (ok ? "Yes" : "No") << endl;
}