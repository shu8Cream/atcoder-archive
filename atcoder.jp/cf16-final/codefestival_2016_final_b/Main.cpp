#include <bits/stdc++.h>
#define rep(i,n) for (ll i=1; i<(n+1); i++)
using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  ll sum=0;
  vector<ll> a;
  rep(i,N){
    sum+=i;
    a.push_back(i);
    if(N<sum){
      ll rm_i=sum-N;
      a.erase(a.begin()+rm_i-1);
      break;
    }else if(N==sum){
      break;
    }
  }
  for(const auto& v :a){
    cout << v <<endl;
  }
}