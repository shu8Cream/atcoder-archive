/**
*    author:  shu8Cream
*    created: 09.03.2021 11:10:04
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
    int n,k; string s;
    cin >> n >> k >> s;
    if(k>=n){
        cout << n-1 << endl;
        return 0;
    }
    int cnt = 0;
    rep(i,n-1){
        if(s[i]!=s[i+1]) cnt++;
    }
    cout << n-1-max(0, cnt-2*k) << endl;
}