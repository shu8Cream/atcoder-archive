/**
*    author:  shu8Cream
*    created: 12.10.2021 22:15:36
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
    int n; cin >> n;
    vi A(3); rep(i,3) cin >> A[i];
    vi l(n); rep(i,n) cin >> l[i];
    ll ans = INF;
    rep(s,1<<(2*n)){
        vi a(3);
        ll res = 0;
        rep(i,n){
            int bit = 0;
            if(s>>(2*i)&1) bit+=1;
            if(s>>(2*i+1)&1) bit+=2;
            if(bit==1){
                if(a[0]) res+=10;
                a[0] += l[i];
            }else if(bit==2){
                if(a[1]) res+=10;
                a[1] += l[i];
            }else if(bit==3){
                if(a[2]) res+=10;
                a[2] += l[i];
            }
        }
        if(!a[0] || !a[1] || !a[2]) continue;
        sort(all(a));
        ll cnt = INF;
        do{
            ll tmp = 0;
            rep(j,3) tmp+=abs(a[j]-A[j]);
            chmin(cnt, tmp);
        }while(next_permutation(all(a)));
        chmin(ans, res+cnt);
    }
    cout << ans << endl;
}