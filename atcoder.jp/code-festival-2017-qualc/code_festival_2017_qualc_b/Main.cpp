/**
*    author:  shu8Cream
*    created: 03.03.2021 16:39:30
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
    int n;
    cin >> n;
    vi a(n);
    int tmp = 0;
    rep(i,n){
        cin >> a[i];
        if(a[i]%2==0) tmp++;
    }
    int ans = pow(3,n)-pow(2,tmp);
    cout << ans << endl;
}