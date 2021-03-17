/**
*    author:  shu8Cream
*    created: 17.03.2021 17:44:18
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
    string s;
    cin >> s;
    int n = s.size();
    vi ans(n);
    int cnt = 0, cur = 0, r = 0;
    rep(i,n){
        cnt++;
        if(s[i]=='R') r++;
        if(s[i]=='R' && s[i]!=s[i+1]) cur = i;
        if(s[i]=='L' && (s[i]==n-1 || s[i]!=s[i+1])){
            if(cnt%2==0) { ans[cur] = cnt/2; ans[cur+1] = cnt/2; }
            else { ans[cur]=(r+1)/2+(cnt-r)/2; ans[cur+1]=(cnt-r+1)/2+r/2;}
        }
        if(s[i]=='L' && (s[i]==n-1 || s[i]!=s[i+1])) {cnt=0; r=0;}
    }
    rep(i,n) cout << ans[i] << endl;
}