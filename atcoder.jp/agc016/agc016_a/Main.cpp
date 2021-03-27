/**
*    author:  shu8Cream
*    created: 27.03.2021 16:16:18
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
    int ans = 1e9;
    rep(i,26){
        int tmp = 0, cnt = 0;
        char key = 'a'+i;
        rep(j,n){
            if(s[j]==key){
                tmp=max(tmp, cnt);
                cnt=0;
            }else cnt++;
        }
        tmp = max(tmp, cnt);
        ans=min(ans,tmp);
    }
    cout << ans << endl;
}