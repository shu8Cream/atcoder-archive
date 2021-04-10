/**
*    author:  shu8Cream
*    created: 10.04.2021 22:28:27
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
    int n;
    cin >> n;
    vi t(n); rep(i,n) cin >> t[i];
    sort(all(t));
    cout << t[0] << endl;
}