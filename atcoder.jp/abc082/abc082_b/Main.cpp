/**
*    author:  shu8Cream
*    created: 13.12.2020 16:00:02
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    string s,t;
    cin >> s >> t;
    if(s<t){
        cout << "Yes" << endl;
        return 0;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    rep(i, s.size()){
        rep(j,t.size()){
            if(s[i]<t[j]){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}