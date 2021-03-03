/**
*    author:  shu8Cream
*    created: 03.03.2021 11:26:14
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
    string s; ll k;
    cin >> s >> k;
    int n = s.size();
    ll ans = 0;
    vi cnt;
    ll tmp = 1;
    rep(i,n-1){
        if(s[i]==s[i+1]) tmp++;
        else{
            cnt.push_back(tmp);
            tmp=1;
        }
    }
    cnt.push_back(tmp);
    int p = cnt.size();
    if(s[0]!=s[n-1]) rep(i,p) ans+=cnt[i]/2*k;
    else{
        if(p==1){
            cout << cnt[0]*k/2 << endl;
            return 0;
        }
        ans+=cnt[0]/2;
        ans+=cnt[p-1]/2;
        rep(i,p-2) ans+=cnt[i+1]/2*k;
        ans+=(cnt[0]+cnt[p-1])/2*(k-1);
    }
    cout << ans << endl;
}