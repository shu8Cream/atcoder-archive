#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i=0; i<N; i++){
    cin >> a.at(i);
  }
  int A=0, B=0;
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for(int i=0; i<N; i++){
  	if(i%2==0){
      A+=a.at(i);
    }else{
      B+=a.at(i);
    }
  }
  cout << A-B << endl;
}