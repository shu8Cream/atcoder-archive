/**
*    author:  shu8Cream
*    created: 05.04.2021 23:49:52
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
    string a,b,c;
    cin >> a >> b >> c;
    int n = a.size() / 2;
    map<char,int> am,bm,cm;
    for(auto p : a) am[p]++;
    for(auto p : b) bm[p]++;
    for(auto p : c) cm[p]++;
    int m = 0, M = 0;
    rep(i,26){
        m += max(0,cm[i+'A']-bm[i+'A']);
        M += min(cm[i+'A'],am[i+'A']);
    }
    cout << (m<=n && n<=M ? "YES" : "NO") << endl;
}