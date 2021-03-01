/**
*    author:  shu8Cream
*    created: 01.03.2021 20:15:09
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
    int n,m;
    string name,kit;
    cin >> n >> m >> name >> kit;
    vi k(26),na(26);
    rep(i,m) k[kit[i]-'A']++;
    rep(i,n) na[name[i]-'A']++;
    int ans = 1;
    rep(i,26){
        if(na[i]>0 && k[i]==0){
            cout << -1 << endl;
            return 0;
        }
        if(k[i]!=0 && na[i]>k[i]) ans=max(ans, (na[i]+k[i]-1)/k[i]);
    }
    cout << ans << endl;
}