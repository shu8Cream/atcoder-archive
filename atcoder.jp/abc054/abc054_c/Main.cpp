/**
*    author:  shu8Cream
*    created: 10.04.2021 13:55:17
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
    vvi to(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vi a(n-1);
    rep(i,n-1) a[i]=i+1;
    int ans = 0;
    do{
        bool ok = true;
        rep(i,n-1){
            bool f = false;
            if(!i){
                for(auto p : to[i])
                    if(a[i]==p) f = true;
            }else{
                for(auto p : to[a[i-1]])
                    if(a[i]==p) f = true;
            }
            if(!f){
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }while(next_permutation(all(a)));
    cout << ans << endl;
}