/**
*    author:  shu8Cream
*    created: 11.02.2021 12:59:59
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
   string s;
   cin >> s;
   int n = s.size();
   reverse(all(s));
   int a=0,b=0; 
   rep(i,n){
     if(i%2==0) a+=s[i]-'0';
     else b+=s[i]-'0';
   }
   cout << b << " " << a << endl;
}