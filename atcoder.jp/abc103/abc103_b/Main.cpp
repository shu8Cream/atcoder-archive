/**
*    author:  shu8Cream
*    created: 09.01.2021 15:34:30
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
    string s,t;
    cin >> s >> t;
    rep(i,s.size()){
        if(s==t){
            cout << "Yes" << endl;
            return 0;
        }
        s = s.substr(1,s.size()-1) + s[0];
    }
    cout << "No" << endl;
}