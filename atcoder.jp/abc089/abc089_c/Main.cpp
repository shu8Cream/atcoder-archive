/**
*    author:  shu8Cream
*    created: 13.12.2020 15:15:11
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

const char march[] = {'M', 'A', 'R', 'C', 'H'}; 

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    ll m=0, a=0, r=0, c=0, h=0;
    rep(i,n){
        rep(j,5){
            if(s[i][0]==march[j] && j==0) m++;
            if(s[i][0]==march[j] && j==1) a++;
            if(s[i][0]==march[j] && j==2) r++;
            if(s[i][0]==march[j] && j==3) c++;
            if(s[i][0]==march[j] && j==4) h++;
        }
    }
    ll ans=m*a*r + m*a*c + m*a*h + m*r*c + m*r*h + m*c*h + a*r*c + a*r*h + a*c*h + r*c*h;
    cout << ans << endl;
}