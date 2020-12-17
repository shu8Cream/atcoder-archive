/**
*    author:  shu8Cream
*    created: 17.12.2020 20:37:09
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    int n;
    cin >> n;
    vi c(n-1),s(n-1),t(n-1);
    rep(i,n-1) cin >> c[i] >> s[i] >>t[i];
    vi ans;
    rep(i,n){
        int now=0;
        for(int j=i; j<n-1; j++){
            if(now<s[j]) now=s[j];
            else if(now%t[j]==0);
            else now+=t[j]-now%t[j];
            now+=c[j];
        }
        ans.push_back(now);
    }
    rep(i,n) cout << ans[i] << endl;
}