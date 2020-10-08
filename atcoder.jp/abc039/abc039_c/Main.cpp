#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const string c = "WBWBWWBWBWBW";
const string d = "WBWWBWBWBWWB";
const string e = "WWBWBWBWWBWB";
const string f = "WBWBWBWWBWBW";
const string g = "WBWBWWBWBWWB";
const string a = "WBWWBWBWWBWB";
const string b = "WWBWBWWBWBWB";

int main(){
  string s;
  cin >> s;
  int cntc=0,cntd=0,cnte=0,cntf=0,cntg=0,cnta=0,cntb=0;
  rep(i,12){
    if(c[i]==s[i]) cntc++;
    if(d[i]==s[i]) cntd++;
    if(e[i]==s[i]) cnte++;
    if(f[i]==s[i]) cntf++;
    if(g[i]==s[i]) cntg++;
    if(a[i]==s[i]) cnta++;
    if(b[i]==s[i]) cntb++;
  }
  if(cntc==12) cout << "Do" << endl;
  if(cntd==12) cout << "Re" << endl;
  if(cnte==12) cout << "Mi" << endl;
  if(cntf==12) cout << "Fa" << endl;
  if(cntg==12) cout << "So" << endl;
  if(cnta==12) cout << "La" << endl;
  if(cntb==12) cout << "Si" << endl;
}