/**
*    author:  shu8Cream
*    created: 12.02.2021 14:27:16
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
    int n,d,k;
    cin >> n >> d >> k;
    vi l(d),r(d),s(k),t(k);
    rep(i,d) cin >> l[i] >> r[i];
    rep(i,k) cin >> s[i] >> t[i];
    rep(i,k){
        int ans = 0, tmp = s[i];
        bool isSho = true;
        if(s[i]>t[i]) isSho = false;
        rep(j,d){
            if(isSho && l[j]<=tmp && tmp<=r[j]) tmp=r[j];
            else if(l[j]<=tmp && tmp<=r[j]) tmp=l[j];
            //cerr << tmp << endl;
            ans++;
            if(isSho && tmp>=t[i]) break;
            if(!isSho && tmp<=t[i]) break;
        }
        cout << ans << endl;
    }
}