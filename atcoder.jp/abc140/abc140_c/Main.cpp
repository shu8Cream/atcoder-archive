#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> b(n-1);
  vector<int> a(n);
  rep(i,n-1) cin >> b[i];
  a[0]=b[0];
  a[1]=b[0];
  for(int i=1; i<n-1; i++){
    if(b[i]<max(a[i],a[i+1])){
      a[i]=b[i];
      a[i+1]=b[i];
    }else{
      a[i+1]=b[i];
    }
  }
  int sum=0;
  rep(i,n) sum+=a[i];
  
  cout << sum << endl;
}