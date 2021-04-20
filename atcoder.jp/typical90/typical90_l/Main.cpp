/**
*    author:  shu8Cream
*    created: 13.04.2021 08:55:57
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
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
        if(par[x] > par[y]) swap(x,y);
        for(auto p : mp[y]){
            mp[x][p.first] += p.second;
        }
        mp[y] = map<int,int>();
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) {return find(x) == find(y);}
    int size(int x) {return -par[find(x)];}
};

vi dx = {1,0,-1,0};
vi dy = {0,1,0,-1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w,q;
    cin >> h >> w >> q;
    UnionFind uf(h*w);
    vvi red(h,vi(w));
    rep(_,q){
        int t; cin >> t;
        if(t==1){
            int x,y; cin >> x >> y;
            x--; y--;
            rep(i,4){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                if(!red[nx][ny]) continue;
                int now = x*w+y;
                int next = nx*w+ny; 
                uf.merge(now,next); 
            }
            red[x][y]=1;
        }else{
            int xa,ya,xb,yb;
            cin >> xa >> ya >> xb >> yb;
            xa--; xb--; ya--; yb--;
            if(!red[xa][ya] || !red[xb][yb]){
                cout << "No" << endl;
                continue;
            }
            int a = xa*w+ya;
            int b = xb*w+yb;
            if(uf.same(a,b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}