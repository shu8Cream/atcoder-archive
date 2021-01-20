/**
*    author:  shu8Cream
*    created: 20.01.2021 20:27:16
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
    string s,t;
    string at = "atcoder";
    cin >> s >> t;
    bool ok = false;
    int cnt = 0;
    rep(i,s.size()){
        if(s[i]!=t[i] && s[i]=='@'){
            rep(j,7){
                if(t[i]==at[j]) cnt++;
            }
        }
        else if(s[i]!=t[i] && t[i]=='@'){
            rep(j,7){
                if(s[i]==at[j]) cnt++;
            }
        }else if(s[i]==t[i]) cnt++;
    }
    if(cnt==s.size()) ok = true;
    cout << (ok ? "You can win" : "You will lose") << endl;
}