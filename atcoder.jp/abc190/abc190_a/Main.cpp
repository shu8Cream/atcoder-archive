/**
*    author:  shu8Cream
*    created: 30.01.2021 20:41:54
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
    int a,b,c;
    cin >> a >> b >> c;
    bool tk = false;
    if(c==0 && a>b) tk=true;
    if(c==1 && a>=b) tk=true;
    cout << (tk ? "Takahashi" : "Aoki") << endl;
}