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

int main(){
  int n;
  cin >> n;
  double sum=0;
  rep(i,n){
    double x;
    string s;
    cin >> x >> s;
    if(s=="JPY") sum+=x;
    else sum+=x*380000;
  }
  printf("%.06lf", sum);
}