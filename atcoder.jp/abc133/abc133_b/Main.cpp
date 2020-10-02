#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int x[10][10];

int main(){
  int n,d;
  cin >> n >> d;
  rep(i,n)rep(j,d) cin >> x[i][j];
  int sum=0,cnt=0;
  rep(i,n){
    for(int j=i+1; j<n; j++){
      rep(k,d){
        sum=sum+(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
      }
      rep(k,sum+1){
        if(k*k==sum) cnt++;
      }
      sum=0;
    }
  }
  cout << cnt << endl;
}