/**
*    author:  shu8Cream
*    created: 02.04.2021 19:47:10
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,a,b;
    cin >> n >> a >> b;
    vi h(n);
    rep(i,n) cin >> h[i];
    ll ok = 1e10, ng = -1;
    while(ok-ng>1){
        ll mid = (ng + ok) / 2;
        ll cnt = 0;
        rep(i,n){
            if(h[i]>b*mid) cnt+=(h[i]-b*mid+a-b-1)/(a-b);
        }
        if(cnt>mid) ng = mid;
        else ok = mid;
    }
    cout << ok << endl;
}