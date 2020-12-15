/**
*    author:  shu8Cream
*    created: 15.12.2020 21:58:39
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

const char ruis[] = {'z', 'b', 'd', 't', 'f', 'l', 's', 'p', 'h', 'n'};
const char carol[] = {'r', 'c', 'w', 'j', 'q', 'v', 'x', 'm', 'k', 'g'};

int main() {
    int n;
    cin >> n;
    vector<string> w(n);
    rep(i,n) cin >> w[i];

    vector<string> ans;
    rep(i,n){
        string a = "";
        rep(j,w[i].size()){
            if(w[i][j]=='.' || w[i][j]==',') continue;
            if(isupper(w[i][j])) w[i][j]-='A'-'a';
            rep(k,10) if(ruis[k]==w[i][j]) a+=to_string(k);
            rep(k,10) if(carol[k]==w[i][j]) a+=to_string(k);
        }
        if(a=="") continue;
        ans.push_back(a);
    }
    
    if(!ans.empty()) cout << ans[0];
    if(!ans.empty()) rep(i,ans.size()-1) cout << " " << ans[i+1];
    cout << endl; 
}