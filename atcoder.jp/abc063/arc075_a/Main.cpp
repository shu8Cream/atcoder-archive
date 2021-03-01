/**
*    author:  shu8Cream
*    created: 01.03.2021 23:43:55
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
    vi s(n);
    rep(i,n) cin >> s[i];
    sort(all(s));
    int ans = 0;
    rep(i,n) ans+=s[i];
    if(ans%10==0){
        rep(i,n){
            if(s[i]%10!=0){
                ans-=s[i];
                break;
            }
        }
        if(ans%10==0) ans=0;
    }
    cout << ans << endl;
}