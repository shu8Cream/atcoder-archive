/**
*    author:  shu8Cream
*    created: 10.01.2021 13:56:03
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
    string s;
    cin >> n >> s;
    ll r=0,g=0,b=0;
    rep(i,n){
        if(s[i]=='R') r++;
        if(s[i]=='G') g++;
        if(s[i]=='B') b++;
    }
    ll cnt=0;
    rep(i,n){
        for(int j = 0; j+2*i+2<n; j++){
            if(s[j]!=s[j+i+1] && s[j+i+1]!=s[j+2*i+2] && s[j+2*i+2]!=s[j]) cnt++;
        }
    }
    ll ans = r*g*b-cnt;
    cout << ans << endl;
}