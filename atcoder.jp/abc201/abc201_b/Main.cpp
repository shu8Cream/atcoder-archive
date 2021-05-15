/**
*    author:  shu8Cream
*    created: 15.05.2021 20:32:40
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int,string>> m(n);
    rep(i,n){
        string s; int t;
        cin >> s >> t;
        m[i] = {t,s};
    }
    sort(rall(m));
    cout << m[1].second << endl;
}