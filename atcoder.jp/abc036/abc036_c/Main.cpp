/**
*    author:  shu8Cream
*    created: 15.01.2021 11:31:10
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using vi = vector<int>;

template <typename T>
vector<T> compress(vector<T> a){
    vector<T> b;
    set<T> s;
    int n = a.size();
    rep(i,n) s.insert(a[i]);
    map<T,T> m;
    int i=0;
    for(auto p : s){
        m[p]=i;
        i++;
    }
    rep(i,n) b.push_back(m[a[i]]);
    return b;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    vi b = compress(a);
    rep(i,n) cout << b[i] << endl;
}