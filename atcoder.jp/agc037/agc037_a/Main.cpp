/**
*    author:  shu8Cream
*    created: 24.03.2021 13:47:37
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
    int n = s.size();
    vector<string> a;
    int ans = 0;
    a.push_back(to_string(s[0]));
    string tmp = "";
    rep(i,n){
        tmp+=s[i];
        if(a.back()!=tmp){
            a.push_back(tmp);
            tmp="";
            ans++;
        }
    }
    cout << ans << endl;
}