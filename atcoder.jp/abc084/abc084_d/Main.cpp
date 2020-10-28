#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int MAX = 101010;
  //エラトステネス
  vi is_prime(MAX,1);
  is_prime[0]=0,is_prime[1]=0;
  for(int i=2; i<MAX; i++){
    if(!is_prime[i]) continue;
    for(int j=i*2; j<MAX; j+=i) is_prime[j]=0;
  }
  //2017likeか判定する配列
  vi a(MAX,0);
  rep(i,MAX){
    if(i%2==0) continue;
    if(is_prime[i] && is_prime[(i+2)/2]) a[i]=1;
  }
  //累積和
  vi s(MAX+1, 0);
  rep(i,MAX) s[i+1]=s[i]+a[i];
  
  //クエリ処理
  int q;
  cin >> q;
  rep(i,q){
    int l,r;
    cin >> l >> r;
    ++r;
    cout << s[r]-s[l] << endl;
  }
}