/**
*    author:  shu8Cream
*    created: 11.04.2021 11:36:50
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
    int n;
    cin >> n;
    vi w(n);
    rep(i,n) cin >> w[i];
    set<int> cnt;
    rep(i,n){
        for(auto v : cnt){
            if(v>=w[i]){
                cnt.erase(v);
                cnt.insert(w[i]);
                break;
            }
        }
        cnt.insert(w[i]);
    }
    cout << cnt.size() << endl;
}