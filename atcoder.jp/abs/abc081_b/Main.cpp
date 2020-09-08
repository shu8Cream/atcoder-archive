#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  int answer=29;
  for(int i=0; i<N; i++){
    int cnt=0;
    while(A.at(i)>0){
      if (A.at(i) % 2 > 0) {
      	break;
      }
      A.at(i) /= 2;
      cnt++;
    }
    if(cnt<answer)
      answer=cnt;
  }
  cout << answer << endl;
}