/**
*    author:  shu8Cream
*    created: 19.01.2021 21:05:42
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
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    char a,b;
    cin >> a >> b;
    if(a=='H' && b=='H') cout << 'H' << endl;
    if(a=='H' && b=='D') cout << 'D' << endl;
    if(a=='D' && b=='H') cout << 'D' << endl;
    if(a=='D' && b=='D') cout << 'H' << endl;
}