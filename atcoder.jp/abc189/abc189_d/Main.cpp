/**
*    author:  shu8Cream
*    created: 23.01.2021 20:47:02
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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    ll ans=1;
    rep(i,n){
        if(s[i]=="OR") ans+=1LL<<(i+1);
    }
    cout << ans << endl;
}