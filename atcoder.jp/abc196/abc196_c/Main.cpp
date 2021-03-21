/**
*    author:  shu8Cream
*    created: 21.03.2021 15:10:02
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    string s = to_string(n);
    int dig = s.size();
    ll num1 = n / (ll)pow(10,dig/2);
    int ans = 0;
    for(int i=1; i<=num1; i++){
        string t = to_string(i) + to_string(i); 
        if(stoll(t) <= n) ans++; 
    }
    cout << ans << endl;
}