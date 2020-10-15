#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<string> a={"Sunny", "Cloudy", "Rainy"};

int main(){
  string s;
  cin >> s;
  if(a[0]==s) cout << "Cloudy" << endl;
  if(a[1]==s) cout << "Rainy" << endl;
  if(a[2]==s) cout << "Sunny" << endl;
}