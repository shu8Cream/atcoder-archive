/**
*    author:  shu8Cream
*    created: 18.04.2021 20:52:17
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    set<int> ans;
    int M = max(a,b);
    int sumA = (M+1)*M/2, sumB = sumA;
    rep(i,a-1){
        ans.insert(i+1);
        sumA-=i+1;
    }
    rep(i,b-1){
        ans.insert(-i-1);
        sumB-=i+1;
    }
    if(ans.count(sumA) || ans.count(sumB)){
        sumA+=10000000;
        sumB+=10000000;
    }
    ans.insert(sumA); ans.insert(-sumB);
    for(auto p : ans){
        cout << p << endl;
    }
}