/**
*    author:  shu8Cream
*    created: 15.02.2021 16:25:27
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
    string s; int k;
    cin >> s >> k;
    int n = s.size();
    set<string> se;
    rep(i,n-k+1){
        se.insert(s.substr(i,k));
    }
    cout << se.size() << endl;
}