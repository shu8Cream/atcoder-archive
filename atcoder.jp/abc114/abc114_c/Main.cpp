/**
*    author:  shu8Cream
*    created: 05.04.2021 22:24:41
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
void f(ll cur, int use, int &res){
    if(cur>n) return;
    if(use==0b111) res++;
    f(cur*10+7, use|0b001, res);
    f(cur*10+5, use|0b010, res);
    f(cur*10+3, use|0b100, res);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    f(0,0,ans);
    cout << ans << endl;
}