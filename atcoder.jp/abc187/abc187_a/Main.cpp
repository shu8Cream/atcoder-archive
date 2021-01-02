/**
*    author:  shu8Cream
*    created: 02.01.2021 20:42:10
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
    string a,b;
    cin >> a >> b;
    int suma=0, sumb=0;
    rep(i,3){
        suma+=int(a[i]-'0');
        sumb+=int(b[i]-'0');
    }
    if(suma>=sumb) cout << suma << endl;
    else cout << sumb << endl;
}