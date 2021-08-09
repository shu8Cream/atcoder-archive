/**
*    author:  shu8Cream
*    created: 08.08.2021 20:46:22
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
int n;
vvi to;

vector<P> path;
vi seen;
void dfs(int s, int& ptr){
    seen.resize(n);
    path.push_back({ptr++,s+1});
    seen[s] = 1;
    int cnt = 0;
    for(auto v : to[s]){
        if(seen[v]){
            cnt++;
            continue;
        }
        dfs(v,ptr);
        path.push_back({ptr++,s+1});
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    to.resize(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i,n) sort(all(to[i]));
    int ptr = 0;
    dfs(0,ptr);
    sort(all(path));
    rep(i,path.size()) cout << path[i].second << " ";
    cout << endl;
}