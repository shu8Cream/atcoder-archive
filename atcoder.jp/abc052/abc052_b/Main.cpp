/**
*    author:  shu8Cream
*    created: 12.03.2021 00:00:20
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
    int cnt = 0;
    vi ans;
    ans.push_back(0);
    rep(i,n){
        if(s[i]=='I') cnt++;
        else cnt--;
        ans.push_back(cnt);
    }
    sort(all(ans));
    cout << ans[ans.size()-1] << endl;
}