/**
*    author:  shu8Cream
*    created: 23.02.2021 23:08:47
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
    int plus = 0, mult = 0;
    rep(i,n){
        if(s[i]=='+') plus++;
    }
    int ans = plus+1;
    int tmp = 1;
    rep(i,n){
        if(tmp && s[i]=='0'){
            ans--;
            tmp=0;
        }
        if(s[i]=='+') tmp=1;
    }
    cout << ans << endl;
}