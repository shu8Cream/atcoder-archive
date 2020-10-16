#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int x;
  cin >> x;
  for(int i=-120; i<120; i++){
    for(int j=-120; j<120; j++){
      if(x==pow(i,5)-pow(j,5)){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
}