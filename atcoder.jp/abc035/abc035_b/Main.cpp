/**
*    author:  shu8Cream
*    created: 25.01.2021 11:35:53
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
    string s; int t;
    cin >> s >> t;
    int ans = 0;
    int u=0,d=0,l=0,r=0,h=0;
    rep(i,s.size()){
        if(s[i]=='U') u++;
        if(s[i]=='D') d++;
        if(s[i]=='L') l++;
        if(s[i]=='R') r++;
        if(s[i]=='?') h++;
    }
    if(t==1) ans+=abs(u-d)+abs(l-r)+h;
    else{
        ans+=abs(u-d)+abs(l-r);
        if(ans>=h) ans-=h;
        else if((ans-h)%2==0) ans=0;
        else ans=1;
    }
    cout << ans << endl;
}