/**
*    author:  shu8Cream
*    created: 19.03.2021 12:53:17
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
    string s;
    cin >> s;
    int n = s.size();
    bool ok = true;
    if(n%2==1) ok = false;
    for(int i=0; i<n; i+=2){
        if(!(s[i]=='h' && s[i+1]=='i')) ok=false;
    }
    cout << (ok ? "Yes" : "No") << endl;
}