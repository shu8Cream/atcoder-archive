/**
*    author:  shu8Cream
*    created: 12.04.2021 23:45:36
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
    int n; string s;
    cin >> n >> s;
    int ans = -1;
    vector<string> t;
    string a = "b";
    rep(i,100){
        t.push_back(a);
        if(i%3==0){
            a = "a" + a + "c";
        }else if(i%3==1){
            a = "c" + a + "a";
        }else{
            a = "b" + a + "b";
        }
    }
    rep(i,t.size()){
        // cout << t[i] << endl;
        if(s==t[i]) ans=i;
    }
    cout << ans << endl;
}