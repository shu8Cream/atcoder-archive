#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  double en;
  if(a>b+c){
    en=M_PI*(a+b+c)*(a+b+c);
    en-=M_PI*(a-b-c)*(a-b-c);
  }else if(a+b<c){
    en=M_PI*(a+b+c)*(a+b+c);
  	en-=M_PI*(a+b-c)*(a+b-c);
  }else if(a+c<b){
    en=M_PI*(a+b+c)*(a+b+c);
  	en-=M_PI*(a-b+c)*(a-b+c);
  }else{
    en=M_PI*(a+b+c)*(a+b+c);
  }
  printf("%.10lf\n", en);
}