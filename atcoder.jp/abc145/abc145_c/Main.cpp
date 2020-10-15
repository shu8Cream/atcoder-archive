#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n), a(n);
  rep(i,n){
    cin >> x[i] >> y[i];
    a[i]=i+1;
  }
  double sum=0;
  do{
    rep(i,n-1){
      int xi=abs(x[a[i]-1]-x[a[i+1]-1]);
      int yi=abs(y[a[i]-1]-y[a[i+1]-1]);
      sum+=sqrt(xi*xi+yi*yi);
    }
  }while(next_permutation(a.begin(), a.end()));
  double na=1;
  while(n>0){
    na*=n;
    n--;
  }
  printf("%.07lf", sum/na);
}