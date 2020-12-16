/**
*    author:  shu8Cream
*    created: 16.12.2020 21:41:05
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    int n;
    cin >> n;
    map<int,int> ma;
    vi a(n+2);
    rep(i,n) cin >> a[i], ma[a[i]]++;

    auto solve = [&]() -> bool{
        if(n%3 != 0) return ma[0]==n;
        vi v;
        for(auto i : ma) v.push_back(i.first);
        if(v.size()==1) return (ma[0]==n);
        else if(v.size()==2) return (ma[0]==n/3);
        else if(v.size()==3) {
            if((v[0]^v[1]^v[2]) != 0) return false;
            return (ma[v[0]]==n/3 && ma[v[1]]==n/3 && ma[v[2]]==n/3);
        }else return false;
    };
    cout << (solve() ? "Yes" : "No") << endl;
}