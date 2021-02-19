/**
*    author:  shu8Cream
*    created: 19.02.2021 12:00:50
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
    int ans = 0;
    for(int i=1; i<n; i++){
        if((n-i)%2!=0) continue;
        if(s.substr(0,(n-i)/2) == s.substr((n-i)/2, (n-i)/2)){
            ans=n-i;
            break;
        }
    }
    cout << ans << endl;
}