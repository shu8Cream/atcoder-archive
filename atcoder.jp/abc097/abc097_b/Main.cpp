/**
*    author:  shu8Cream
*    created: 05.03.2021 20:14:04
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
    int x;
    cin >> x;
    set<int> s;
    s.insert(1);
    for(int i=2; i<=1000; i++){
        for(int j=2; pow(i,j)<=x; j++){
            s.insert(pow(i,j));
        }
    }
    cout << *rbegin(s) << endl;
}