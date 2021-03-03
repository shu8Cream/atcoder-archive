/**
*    author:  shu8Cream
*    created: 03.03.2021 18:21:59
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
    int a,b;
    cin >> a >> b;
    int n = 1, nb = b;
    while(b/=10) n++;
    while(n--) a*=10;
    int ans=a+nb;
    bool ok = false;
    for(int i=1; i<500; i++){
        if(i*i==ans) ok=true;
    }
    cout << (ok ? "Yes" : "No") << endl;
}