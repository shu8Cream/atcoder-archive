#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
	vector<char> s(n);
    rep(i,n) cin>>s[i];
    int ans=0;
    rep(i,n){
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') ans++;
    }
    cout << ans << endl;
}