/**
*    author:  shu8Cream
*    created: 28.03.2021 20:45:40
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
    int t;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n%2==1) cout << "Odd" << endl;
        else if(n%4==0) cout << "Even" << endl;
        else cout << "Same" << endl; 
    }
}