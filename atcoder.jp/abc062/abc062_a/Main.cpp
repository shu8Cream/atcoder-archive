/**
*    author:  shu8Cream
*    created: 19.03.2021 12:53:04
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
    int x,y;
    cin >> x >> y;
    set<int> g1,g2;
    g1.insert(1);
    g1.insert(3);
    g1.insert(5);
    g1.insert(7);
    g1.insert(8);
    g1.insert(10);
    g1.insert(12);

    g2.insert(4);
    g2.insert(6);
    g2.insert(9);
    g2.insert(11);
    bool ok = false;
    if(g1.count(x) && g1.count(y)) ok = true;
    if(g2.count(x) && g2.count(y)) ok = true;
    cout << (ok ? "Yes" : "No") << endl;
}