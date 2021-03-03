/**
*    author:  shu8Cream
*    created: 03.03.2021 21:27:36
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
    string s;
    cin >> s;
    bool ok = false;
    if(s.size()>=4 && s.substr(0,4)=="YAKI") ok=true;
    cout << (ok ? "Yes" : "No") << endl;
}