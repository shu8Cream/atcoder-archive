#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> L(N);
  for(int i=0; i<N; i++){
    cin >> L.at(i);
  }
  int cnt=0;
  sort(L.begin(),L.end());
  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      for(int k=j+1; k<N; k++){
    	if(L.at(i)+L.at(j)>L.at(k)&&L.at(i)!=L.at(j)&&L.at(j)!=L.at(k)){
          cnt++;
        }
      }
  	}
  }
  cout << cnt << endl;
}