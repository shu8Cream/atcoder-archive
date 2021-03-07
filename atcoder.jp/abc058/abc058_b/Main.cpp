/**
*    author:  shu8Cream
*    created: 07.03.2021 23:43:31
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
    string o,e;
    cin >> o >> e;
    string ans;
    rep(i,e.size()){
        ans+=o[i];
        ans+=e[i]; 
    }
    if(o.size()-e.size()==1) ans+=o[o.size()-1];
    cout << ans << endl;
}