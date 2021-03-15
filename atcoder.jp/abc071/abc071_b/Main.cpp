/**
*    author:  shu8Cream
*    created: 15.03.2021 11:17:32
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
    vi c(26);
    rep(i,s.size()){
        c[s[i]-'a']++;
    }
    char ans = '?';
    rep(i,26){
        if(!c[i]){
            ans=char('a'+i);
            break;
        }
    }
    if(ans!='?') cout << ans << endl;
    else cout << "None" << endl;
}