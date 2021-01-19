/**
*    author:  shu8Cream
*    created: 19.01.2021 21:05:52
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
    vi l(n);
    rep(i,n) cin >> l[i];
    sort(all(l));
    int ans = 0;
    rep(i,n){
        for(int j=i+1; j<n; j++){
            int a = lower_bound(all(l), l[i]+l[j])-l.begin();
            if(a>j) ans+=a-j-1;
        }
    }
    cout << ans << endl;
}