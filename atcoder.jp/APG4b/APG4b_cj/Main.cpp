#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> score(N);
  int sum;
  for(int i=0; i<N; i++){
  	cin >> score.at(i); 
    sum+=score.at(i);
  }
  int mean=sum/N;
  for(int i=0; i<N; i++){
    int diff=mean-score.at(i);
    if(diff<0){
      cout << -1*diff << endl;
    }else{
      cout << diff << endl;
    }
  }
}