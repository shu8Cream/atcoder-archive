#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> X(N);
  for(int i=0; i<N; i++){
    cin >> X.at(i);
  }
  sort(X.begin(),X.end());
  int answer=0,en=0;
  for(int i=X.at(0); i<X.at(N-1); i++){
    for(int j=0; j<N; j++){
      en+=(i-X.at(j))*(i-X.at(j));
    }
    if(i==X.at(0)){
      answer=en;
      continue;
    }
    answer=min(answer,en);
    en=0;
  }
  cout << answer << endl;
}