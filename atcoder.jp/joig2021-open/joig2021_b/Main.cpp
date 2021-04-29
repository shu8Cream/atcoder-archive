/**
*    author:  shu8Cream
*    created: 29.04.2021 14:13:44
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k; string t;
    cin >> n >> k >> t;
    k--;
    rep(i,n){
        if(i<k) continue;
        if(isupper(t[i])) t[i]=tolower(t[i]);
        else t[i]=toupper(t[i]);
    }
    cout << t << endl;
}