/**
*    author:  shu8Cream
*    created: 07.04.2021 23:04:00
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
    vi a(5);
    rep(i,5) cin >> a[i];
    vi ans;
    rep(i,5)for(int j=i+1; j<5; j++){
        for(int k=j+1; k<5; k++){
            ans.push_back(a[i]+a[j]+a[k]);
        }
    }
    sort(all(ans));
    cout << ans[2] << endl;
}