#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  int cnt=0;
  vi a(10050);
  for(int x=1; x*x<n; x++){
    for(int y=1; y*y<n; y++){
      for(int z=1; z*z<n; z++){
        int v=x*x+y*y+z*z+x*y+y*z+z*x;
        if(v<10050)
        a[v-1]++;
      }
    }
  }
  rep(i,n){
    cout << a[i] << endl;
  }
}