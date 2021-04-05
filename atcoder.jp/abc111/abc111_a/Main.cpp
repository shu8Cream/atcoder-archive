/**
*    author:  shu8Cream
*    created: 05.04.2021 21:36:07
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
    rep(i,3){
        if(n[i]-'0'==1) n[i]='9';
        else if(n[i]-'0'==9) n[i]='1';
    }
    cout << n << endl;
}