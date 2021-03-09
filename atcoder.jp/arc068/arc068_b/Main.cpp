/**
*    author:  shu8Cream
*    created: 09.03.2021 10:57:02
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
    vi a(n);
    rep(i,n) cin >> a[i];
    set<int> s;
    rep(i,n) s.insert(a[i]);
    int ans = s.size();
    if(ans%2==0) ans--;
    cout << ans << endl;
}