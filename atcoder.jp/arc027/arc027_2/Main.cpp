/**
*    author:  shu8Cream
*    created: 03.04.2021 15:38:30
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

struct UnionFind{
    vector<int> par;
    vector<map<int, int>> mp;
    UnionFind(int n=0): par(n, -1), mp(n) {}
    int find(int x){
        if(par[x] < 0) return x;
        return par[x] = find(par[x]);
    }
    bool merge(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x,y); //マージテク
        for(auto p : mp[y]){
            mp[x][p.first] += p.second;
        }
        mp[y] = map<int,int>(); //メモリの解放
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) {return find(x) == find(y);}
    int size(int x) {return -par[find(x)];}
};


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; string s1,s2;
    cin >> n >> s1 >> s2;
    UnionFind uf(36);
    rep(i,n){
        int s = isalpha(s1[i]) ? s1[i]-'A'+10 : s1[i]-'0';
        int t = isalpha(s2[i]) ? s2[i]-'A'+10 : s2[i]-'0';
        uf.merge(s,t);
    }
    ll ans = 1;
    vi used(36);
    rep(i,n){
        int s = isalpha(s1[i]) ? s1[i]-'A'+10 : s1[i]-'0';
        int t = isalpha(s2[i]) ? s2[i]-'A'+10 : s2[i]-'0';
        if(used[uf.find(s)] && used[uf.find(t)]) continue;
        used[uf.find(s)]=1;
        used[uf.find(t)]=1;
        bool f = true;
        rep(j,10){
            if(uf.same(j,s)) f = false;
        }
        if(!i && f) ans*=9;
        if(i && f) ans*=10;
    }
    cout << ans << endl;
}