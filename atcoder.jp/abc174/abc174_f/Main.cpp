/**
*    author:  shu8Cream
*    created: 07.09.2021 21:28:12
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

const int MAX_VAL = 500005;
int a[MAX_VAL]; //要素
int cnt[MAX_VAL]; //区間内のiの個数
int res;        //区間内の種類の数
 
class Mo{
private:
    vector<int> left, right;
    const int width;
    void add(const int id);
    void del(const int id);
 
public:
    vector<int> ans;
 
    Mo(const int n) : width((int)sqrt(n)){}
    // クエリ[l,r)
    void insert(const int l, const int r){
        left.push_back(l), right.push_back(r);
    }
    void solve(){
        const int sz = (int)left.size();
        int nl = 0, nr = 0;
        vector<int> ord(sz);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](const int a, const int b){
            const int c = left[a] / width, d = left[b] / width;
            return (c == d) ? ((c & 1) ? (right[b] < right[a]) : (right[a] < right[b])) : (c < d);
        });
        ans.resize(sz);
        for(const int id : ord){
            while(nl > left[id]) add(--nl);
            while(nr < right[id]) add(nr++);  //add
            while(nl < left[id]) del(nl++);
            while(nr > right[id]) del(--nr);  //del
            ans[id] = res;
        }
    }
};
 
//idは元の配列のインデックス
void Mo::add(const int id)
{
    ++cnt[a[id]];
    if(cnt[a[id]] == 1) ++res;
}
 
void Mo::del(const int id)
{
    --cnt[a[id]];
    if(cnt[a[id]] == 0) --res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    Mo mo(n);
    rep(i,n) cin >> a[i];
    rep(i,q){
        int l,r; cin >> l >> r;
        --l; mo.insert(l,r);
    }
    mo.solve();
    const auto& ans = mo.ans;
    rep(i,q) cout << ans[i] << endl;
}