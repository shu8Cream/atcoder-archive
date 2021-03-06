/**
*    author:  shu8Cream
*    created: 06.03.2021 20:48:03
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
    int n,m;
    cin >> n >> m;
    vi a(n), cnt(n);
    set<int> s;
    rep(i,n){
        cin >> a[i];
        s.insert(i);
    }
    s.insert(n);
    rep(i,m){
        cnt[a[i]]++;
        if(cnt[a[i]]==1) s.erase(a[i]);
    }
    int ans = *s.begin();
    rep(i,n-m){
        cnt[a[i]]--;
        if(cnt[a[i]]==0) s.insert(a[i]);
        cnt[a[i+m]]++;
        if(cnt[a[i+m]]==1) s.erase(a[i+m]);
        int tmp = *s.begin();
        ans=min(ans,tmp);
    }
    cout << ans << endl;
}