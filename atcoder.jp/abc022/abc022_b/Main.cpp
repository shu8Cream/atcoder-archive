/**
*    author:  shu8Cream
*    created: 18.03.2021 17:52:14
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
    vi a(n), cnt(100005);
    rep(i,n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    rep(i,100005){
        ans+=max(cnt[i]-1,0);
    }
    cout << ans << endl;
}