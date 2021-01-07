/**
*    author:  shu8Cream
*    created: 07.01.2021 20:31:25
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

void f(int d, ll v, vector<ll> &s){
    s.push_back(v);
    if(d==10) return;
    for(int i=-1; i<=1; i++){
        int add = (v%10) + i;
        if(add>=0 && add<=9) f(d+1, v*10+add, s);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    vector<ll> s;
    rep(i,9) f(1,i+1,s);
    sort(all(s));
    cout << s[k-1] << endl;
}