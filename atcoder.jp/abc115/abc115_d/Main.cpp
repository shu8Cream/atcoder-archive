/**
*    author:  shu8Cream
*    created: 11.03.2021 22:44:53
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

ll pcnt(int n, ll x){
    ll len = (1LL<<(n+1))-3;
    ll paty = (1LL<<n)-1;
    if(x<=n) return 0;
    else if(x<=len+1) return pcnt(n-1,x-1);
    else if(x<=len+2) return paty + 1;
    else if(x<=(len+1)*2) return paty + 1 + pcnt(n-1,x-len-2);
    else return paty*2+1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; ll x;
    cin >> n >> x;
    cout << pcnt(n,x) << endl;
}