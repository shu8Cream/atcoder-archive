#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
	string s;
	cin>>s;
  	int ans=0,cnt=0;
  	rep(i,s.size()){
    	if(s[i]=='A'||s[i]=='T'||s[i]=='G'||s[i]=='C') cnt++;
   	 	else cnt=0;
        ans=max(ans,cnt);
  	}
  	cout << ans << endl;
}