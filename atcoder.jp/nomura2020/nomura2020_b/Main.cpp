/**
*    author:  shu8Cream
*    created: 18.01.2021 11:45:01
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
    string t;
    cin >> t;
    rep(i,t.size()){
        if(t[i]=='?') t[i]='D';
    }
    cout << t << endl;
}