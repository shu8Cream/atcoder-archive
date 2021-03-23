/**
*    author:  shu8Cream
*    created: 23.03.2021 21:25:23
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
    int n,m;
    cin >> n >> m;
    vi cnt(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        cnt[a]++;
        cnt[b]++;
    }
    bool ok = true;
    rep(i,n) if(cnt[i]%2==1) ok = false;
    cout << (ok ? "YES" : "NO") << endl;
}