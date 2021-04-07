/**
*    author:  shu8Cream
*    created: 07.04.2021 22:55:10
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
    string s; int n;
    cin >> s >> n;
    int len = s.size();
    rep(i,n){
        int l,r;
        cin >> l >> r;
        string a = s.substr(0,l-1);
        string b = s.substr(l-1,r-l+1);
        string c = s.substr(r,len-r);
        reverse(all(b));
        s = a+b+c;
    }
    cout << s << endl;
}