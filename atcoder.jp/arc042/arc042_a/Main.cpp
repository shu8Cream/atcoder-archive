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
  int n,m;
  cin >> n >> m;
  vi a(m);
  rep(i,m) cin >> a[i];
  stack<int> st;
  rep(i,n) st.push(n-i);
  rep(i,m) st.push(a[i]);
  set<int> se;
  rep(i,n+m){
    if(se.count(st.top())) st.pop();
    else{
      cout << st.top() << endl;
      se.insert(st.top());
      st.pop();
    }
  }
}