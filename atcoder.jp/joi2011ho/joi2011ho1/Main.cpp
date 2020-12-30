/**
*    author:  shu8Cream
*    created: 30.12.2020 18:19:24
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int m,n,k;
    cin >> m >> n >> k;
    vector<string> s(m);
    rep(i,m) cin >> s[i];

    vvi rj(m+1, vi(n+1)), ro(m+1, vi(n+1)), ri(m+1, vi(n+1));
    rep(i,m)rep(j,n){
        if(s[i][j]=='J') rj[i+1][j+1]=rj[i][j+1]+rj[i+1][j]-rj[i][j]+1;
        else rj[i+1][j+1]=rj[i][j+1]+rj[i+1][j]-rj[i][j];
        if(s[i][j]=='O') ro[i+1][j+1]=ro[i][j+1]+ro[i+1][j]-ro[i][j]+1;
        else ro[i+1][j+1]=ro[i][j+1]+ro[i+1][j]-ro[i][j];
        if(s[i][j]=='I') ri[i+1][j+1]=ri[i][j+1]+ri[i+1][j]-ri[i][j]+1;
        else ri[i+1][j+1]=ri[i][j+1]+ri[i+1][j]-ri[i][j];
    }
    
    /*
    rep(i,m){
      rep(j,n){
        cerr << rj[i+1][j+1] << " ";
      }
      cerr << endl;
    }
  
    rep(i,m){
      rep(j,n){
        cerr << ro[i+1][j+1] << " ";
      }
      cerr << endl;
    }
  
    rep(i,m){
      rep(j,n){
        cerr << ri[i+1][j+1] << " ";
      }
      cerr << endl;
    }*/

    rep(i,k){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;b--;
        int J=rj[c][d]-rj[a][d]-rj[c][b]+rj[a][b];
        int O=ro[c][d]-ro[a][d]-ro[c][b]+ro[a][b];
        int I=ri[c][d]-ri[a][d]-ri[c][b]+ri[a][b];
        printf("%d %d %d\n", J,O,I);
    }
}