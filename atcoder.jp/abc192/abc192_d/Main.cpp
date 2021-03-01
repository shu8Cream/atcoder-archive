/**
*    author:  shu8Cream
*    created: 27.02.2021 15:19:21
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

string x; ll m;

bool check(ll n){
    ll xx = 0;
    for(char c : x){
        if(xx>m/n) return 0;
        xx*=n;
        xx+=c;
    }
    return xx<=m;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> x >> m;
    for(char& c : x) c-='0';
    if(x.size()==1){
        cout << check(10) << endl;
        return 0;
    }
    const ll d = *max_element(all(x));
    ll ok = d, ng = m+1;
    while(ng-ok>1){
        const ll mid = (ok+ng)/2;
        (check(mid) ? ok : ng) = mid;
    }
    cout << ok - d << endl;
}