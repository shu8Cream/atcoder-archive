/**
*    author:  shu8Cream
*    created: 15.02.2021 17:10:19
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<P> a(n);
    rep(i,n){
        cin >> a[i].first;
        a[i].second=i+1;
    }
    sort(all(a));
    rep(i,n) cout << a[i].second << endl;
}