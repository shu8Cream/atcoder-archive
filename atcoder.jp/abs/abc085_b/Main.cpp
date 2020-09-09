#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  for(int i=0; i<N; i++){
    cin >> d.at(i);
  }
  int rank=1;
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  for(int i=0; i<N-1; i++){
    if(d.at(i)>d.at(i+1)){
      rank++;
    }
  }
  cout << rank << endl;
}