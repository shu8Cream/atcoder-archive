/**
*    author:  shu8Cream
*    created: 02.10.2021 00:09:15
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
    int h,w,k; cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    ll ans = INF;
    rep(b,1<<(h-1)){
        vi cut;
        rep(i,h-1){
            if(b>>i&1) cut.push_back(i);
        }
        ll res = sz(cut);
        vi cnt(sz(cut)+1);
        vi pcnt(sz(cut)+1);
        rep(j,w){
            int idx = 0;
            int pre = 0;
            bool f = false;
            for(int p : cut){
                ll c = 0;
                for(int i=pre; i<p+1; i++){
                    if(s[i][j]=='1') c++;
                }
                pre = p+1;
                cnt[idx] += c;
                pcnt[idx] = c;
                // debug(idx,c,cnt[idx]);
                if(c>k) res = INF;
                if(!f && cnt[idx]>k){
                    res++;
                    f = true;
                }
                idx++;
            }
            ll c = 0;
            for(int i=pre; i<h; i++){
                if(s[i][j]=='1') c++;
            }
            cnt[idx] += c;
            pcnt[idx] = c;
            // debug(idx,c,cnt[idx]);
            if(c>k) res = INF;
            if(!f && cnt[idx]>k){
                res++;
                f = true;
            }
            if(f) cnt = pcnt;
        }
        debug(ans,res);
        chmin(ans,res);
    }
    cout << ans << endl;
}