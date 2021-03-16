/**
*    author:  shu8Cream
*    created: 16.03.2021 19:07:26
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
    int a,b,c;
    cin >> a >> b >> c;
    int ans = 0;
    int ta=a,tb=b,tc=c;
    while(1){
        if(a%2==1 || b%2==1 || c%2==1) break;
        ans++;
        a=tb/2+tc/2;
        b=ta/2+tc/2;
        c=tb/2+ta/2;
        if(ta==a && tb==b && tc==c){
            ans=-1;
            break;
        }
        ta = a; tb = b; tc = c; 
    }
    cout << ans << endl;
}