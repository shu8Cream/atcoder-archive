/**
*    author:  shu8Cream
*    created: 30.10.2021 20:54:40
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
const ll INF = 8e18;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
cout << H << " ";
debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    map<int,deque<int>> m;
    map<int,deque<int>> rm;
    rep(_,q){
        int c; cin >> c;
        if(c==1){
            int x,y; cin >> x >> y;
            x--; y--;
            m[x].push_back(y);
            rm[y].push_back(x);
        }else if(c==2){
            int x,y; cin >> x >> y;
            x--; y--;
            m[x].pop_back();
            rm[y].pop_back();
        }else{
            int x; cin >> x; x--;
            deque<int> ans;
            ans.push_back(x);
            int cur = x;
            while(sz(m[cur])){
                rep(i,sz(m[cur])) ans.push_back(m[cur][i]);
                cur = m[cur].back();
            }
            cur = x;
            while(sz(rm[cur])){
                rep(i,sz(rm[cur])) ans.push_front(rm[cur][i]);
                cur = rm[cur].back();
            }
            cout << sz(ans) << (sz(ans)==0 ? "\n" : " ");
            rep(i,sz(ans)) cout << ans[i]+1 << (i==sz(ans)-1 ? "\n" : " ");
        }
    }
}