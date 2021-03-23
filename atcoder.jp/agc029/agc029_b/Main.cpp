/**
*    author:  shu8Cream
*    created: 22.03.2021 23:27:05
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
    vi a(n); map<int,int> m;
    rep(i,n){
        cin >> a[i];
        m[a[i]]++;
    }
    sort(all(a));
    int ans = 0;
    rep(i,n){
        rep(j,30){
            int t = 1<<(j+1);
            if(t-a[i]<a[i] && m.count(t - a[i]) && m[t-a[i]]>0 && m[a[i]]>0){
                m[t - a[i]]--;
                m[a[i]]--;
                ans++;
                break;
            }
            if(t-a[i]==a[i] && m.count(t - a[i]) && m[t-a[i]]>1){
                m[a[i]]-=2;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}