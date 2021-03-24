/**
*    author:  shu8Cream
*    created: 24.03.2021 09:59:04
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
    map<char,int> m;
    rep(i,s.size()){
        m[s[i]]++;
    }
    for(auto [k,v] : m){
        if(v!=1){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}