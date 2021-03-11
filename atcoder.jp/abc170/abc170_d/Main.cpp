/**
*    author:  shu8Cream
*    created: 11.03.2021 09:36:10
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int MAX = 1001001;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n), b(MAX);
    set<int> s; 
    rep(i,n){
        cin >> a[i];
        b[a[i]]++;
        s.insert(a[i]);
    }
    vector<bool> f(MAX);
    for(auto p : s){
        for(int i=2; i<MAX; i++){
            if(p*i>=MAX) break;
            f[p*i]=true;
        }
    }
    int ans = 0;
    rep(i,n) if(b[a[i]]==1 && !f[a[i]]) ans++;
    cout << ans << endl;
}