/**
*    author:  shu8Cream
*    created: 09.01.2021 15:50:15
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
    set<char> se;
    rep(i,n) se.insert(s[i]);
    int ans = 0;
    rep(i,n-1){
        string x = s.substr(0,i+1);
        string y = s.substr(i+1, n-i-1);
        map<char,int> mx,my;
        rep(j,x.size()) mx[x[j]]=1;
        rep(j,y.size()) my[y[j]]=1;
        int tmp = 0;
        for(auto p : se){
            tmp+=min(mx[p], my[p]);
        }
        ans=max(ans,tmp);
    }
    cout << ans << endl;
}