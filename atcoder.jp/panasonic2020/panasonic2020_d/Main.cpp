/**
*    author:  shu8Cream
*    created: 02.09.2021 20:37:13
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
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

int n;

void dfs(string s, char mx){
    if(sz(s)==n){
        cout << s << endl;
        return;
    }
    for(char c='a'; c<=mx+1; c++){
        string t = s;
        t += c;
        dfs(t, max(mx,c));
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    dfs("", 'a'-1);
}
