/**
*    author:  shu8Cream
*    created: 09.05.2021 22:00:25
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    set<int> a;
    a.insert(3*5*7*11);
    a.insert(2*11);
    a.insert(2*3);
    if(n>=4) a.insert(2*5);
    if(n>=5) a.insert(2*7);
    int p = 2;
    while(a.size()<n){
        if(6*p>10000) break;
        a.insert(6*p);
        p++;
    }
    p = 2;
    while(a.size()<n){
        if(10*p>10000) break;
        a.insert(10*p);
        p++;
    }
    p = 2;
    while(a.size()<n){
        if(14*p>10000) break;
        a.insert(14*p);
        p++;
    }
    p = 2;
    while(a.size()<n){
        if(22*p>10000) break;
        a.insert(22*p);
        p++;
    }
    for(auto p : a){
        cout << p << " ";
    }cout << endl;
}