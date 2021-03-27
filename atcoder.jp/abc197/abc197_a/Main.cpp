/**
*    author:  shu8Cream
*    created: 27.03.2021 20:56:03
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
    char c = s[0];
    s[0]=s[1]; s[1]=s[2];
    s[2]=c;
    cout << s << endl;
}