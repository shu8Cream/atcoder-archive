/**
*    author:  shu8Cream
*    created: 03.04.2021 11:03:00
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
    int ans = 0;
    int right = 0;
    set<int> cnt;
    rep(left,n){
        while(right<n && !cnt.count(a[right])){
            cnt.insert(a[right]);
            right++;
        }
        ans = max(ans, right-left);
        if(left==right) right++;
        else cnt.erase(a[left]);
    }
    cout << ans << endl;
}