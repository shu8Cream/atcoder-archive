/**
*    author:  shu8Cream
*    created: 06.04.2021 20:43:50
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
    string s; cin >> s;
    int n = stoi(s);
    int dig = s.size();
    int a = 0;
    rep(i,dig){
        a+=s[i]-'0';
    }
    cout << (n%a==0 ? "Yes" : "No") << endl;
}