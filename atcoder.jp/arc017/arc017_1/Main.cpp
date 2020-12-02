#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
  int n;
  cin >> n;
  n++;
  vi is_prime(n,1);
  is_prime[0]=0,is_prime[1]=0;
  for(int i=2; i<n; i++){
    if(!is_prime[i]) continue;
    for(int j=i*2; j<n; j+=i) is_prime[j]=0;
  }
  if(is_prime[n-1]) cout << "YES" << endl;
  else cout << "NO" << endl;
}