/**
*    author:  shu8Cream
*    created: 29.04.2021 11:27:54
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    set<string> se;
    vi ans;
    rep(i,n){
        string s; cin >> s;
        if(!se.count(s)) ans.push_back(i+1);
        se.insert(s);
    }
    rep(i,ans.size()) cout << ans[i] << endl;
}