/**
*    author:  shu8Cream
*    created: 31.07.2021 20:47:24
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

const string key = "01234567890123456789";

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string x; cin >> x;
    bool ok = false;
    if(x[0]==x[1] && x[1]==x[2] && x[2]==x[3]) ok = true;
    rep(i,17){
        if(key[i]==x[0] && key[i+1]==x[1] && key[i+2]==x[2] && key[i+3]==x[3]) ok = true;
    }
    if(ok) cout << "Weak" << endl;
    else cout << "Strong" << endl;
}