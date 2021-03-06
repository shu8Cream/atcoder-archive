/**
*    author:  shu8Cream
*    created: 06.03.2021 20:47:43
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
    vector<P> a(n),b(n);
    rep(i,n){
        cin >> a[i].first >> b[i].first;
        a[i].second=i;
        b[i].second=i;
    }
    sort(all(a));
    sort(all(b));
    int ans = 0;
    if(a[0].second==b[0].second) ans=min({max(a[0].first,b[1].first), max(a[1].first,b[0].first), a[0].first+b[0].first});
    else ans = max(a[0].first, b[0].first);
    cout << ans << endl;
}