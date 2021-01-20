/**
*    author:  shu8Cream
*    created: 19.01.2021 20:11:28
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
    vector<ll> a(2019,0);
    ll k = 1;
    ll now = 0;
    a[now]++;
    rep(i,n){
        ll tmp = s[n-1-i]-'0';
        now = (now + tmp * k) % 2019;
        k = (k * 10) % 2019;
        a[now]++;
    }
    ll ans = 0;
    rep(i,a.size()){
        ans+=a[i]*(a[i]-1)/2;
    }
    cout << ans << endl;
}