/**
*    author:  shu8Cream
*    created: 17.10.2021 21:43:59
**/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

using S = ll;
using F = ll;
S op(S a, S b){ return std::min(a, b); }
S e(){ return ll(1e9)+1; }
S mapping(F f, S x){ return x+f; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    string s; cin >> s;
    vi t(n);
    rep(i,n){
        if(s[i]=='(') t[i]=1;
        if(s[i]==')') t[i]=-1;
    }
    vi a(n);
    rep(i,n){
        if(i==0) a[i] = t[i];
        else a[i] += a[i-1] + t[i];
    }

    // rep(i,n) cout << a[i] << (n-1==i ? "\n" : " ");

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

    rep(i,q){
        int c,l,r; cin >> c >> l >> r;
        l--;
        if(c==1){
            if(s[l]!=s[r-1] && s[l]=='(') seg.apply(l,r-1,-2);
            else if(s[l]!=s[r-1] && s[l]==')') seg.apply(l,r-1,2);
            swap(s[l],s[r-1]);
        }else{
            // debug(seg.prod(l,r), seg.get(l), seg.get(r-1));
            if(seg.prod(l,r)>=seg.get(r-1) && seg.get(l)==seg.get(r-1)+1 && s[l]=='(' && s[r-1]==')') cout << "Yes" << endl;
            else cout << "No" << endl; 
        }
    }
}