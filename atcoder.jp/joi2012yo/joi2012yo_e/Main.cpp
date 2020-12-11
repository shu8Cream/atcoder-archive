#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

const int di[] = {-1, -1, 0, 0, 1, 1};
const int dj1[] = {0, 1, -1, 1, 0, 1}; //odd
const int dj2[] = {-1, 0, -1, 1, -1, 0}; //even

int main(){
  int w,h;
  cin >> w >> h;
  vvi c(h+2, vi(w+2));
  rep(i,h)rep(j,w) cin >> c[i+1][j+1];
  
  vvi seen(h+2, vi(w+2,-1));
  queue<P> que;
  int cnt=0;
  que.push({0,0});
  int wall=0;
  while(!que.empty()){
    int i = que.front().first;
    int j = que.front().second;
    que.pop();
    if(i%2==0){
      rep(k,6){
        int ni = i+di[k];
        int nj = j+dj2[k];
        if(ni<0 || ni>=h+2 || nj<0 || nj>=w+2) continue;
      	if(c[ni][nj]==0 && seen[ni][nj]==-1){
          seen[ni][nj]=1;
          que.push({ni,nj});
        }
        if(c[ni][nj]==1) wall++;
      }
    }else{
      rep(k,6){
        int ni = i+di[k];
        int nj = j+dj1[k];
        if(ni<0 || ni>=h+2 || nj<0 || nj>=w+2) continue;
      	if(c[ni][nj]==0 && seen[ni][nj]==-1){
          seen[ni][nj]=1;
          que.push({ni,nj});
        }
        if(c[ni][nj]==1) wall++;
      }
    }
  }
  cout << wall << endl;
}
