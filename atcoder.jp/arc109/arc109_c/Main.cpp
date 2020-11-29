#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int n;
string s;
vector<vector<char>> memo(110, vector<char>(110,'?'));

char win(char i, char j){
  if(i==j) return i;
  if(i!='R' && j!='R') return 'S';
  if(i!='S' && j!='S') return 'P';
  if(i!='P' && j!='P') return 'R';
}

ll mod_pow(ll a, ll b){
  if(b==0) return 1;
  if(b%2==1) return a*mod_pow(a,b-1)%n;
  else return mod_pow(a*a%n, b/2)%n;
}

char vic(ll k, ll i){
  if(k==0) return s[i];
  if(memo[k][i]!='?') return memo[k][i];
  char left = vic(k-1, 0+i);
  char right = vic(k-1, (mod_pow(2,k-1)+i)%n);
  return memo[k][i]=win(left, right);
}

int main(){
  int k;
  cin >> n >> k >> s;
  char ans = vic(k, 0);
  cout << ans << endl;
}