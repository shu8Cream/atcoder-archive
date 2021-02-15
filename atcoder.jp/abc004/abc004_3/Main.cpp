/**
*    author:  shu8Cream
*    created: 15.02.2021 16:05:29
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
    cin >> n;
    string ans="123456";
    rep(i,6){
        if(n/5%6==i) rotate(ans.begin(), ans.begin()+i, ans.end());
    }
    rep(i,n%5){
        swap(ans[i],ans[i+1]);
    }
    cout << ans << endl;
}