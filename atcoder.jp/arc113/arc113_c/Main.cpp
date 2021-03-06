/**
*    author:  shu8Cream
*    created: 06.03.2021 11:06:33
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
    ll ans = 0;
    vi a(26);
    for(int i=n-1; i>=1; i--){
        a[s[i]-'a']++;
        if(s[i]==s[i-1]){
            rep(j,26){
                if(char(j+'a')!=s[i]){
                    ans+=a[j];
                    a[s[i]-'a']+=a[j];
                    a[j]=0;
                }
            }
        }
    }
    cout << ans << endl;
}