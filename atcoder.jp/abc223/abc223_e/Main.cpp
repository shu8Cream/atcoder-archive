/**
*    author:  shu8Cream
*    created: 17.10.2021 21:27:24
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



bool solve1(ll x, ll y, ll a, ll b, ll c){
    rep(i,2){
        rep(j,3){
            ll X = x;
            X-=(a+y-1)/y;
            X-=(b+y-1)/y;
            if(X*y>=c) return true;
            swap(a,b);
            swap(b,c);
        }
        swap(x,y);
    }
    return false;
}

bool solve2(ll x, ll y, ll a, ll b, ll c){
    rep(i,2){
        rep(j,3){
            ll ok = x, ng = -1;
            while(ok-ng>1){
                ll mid = (ok+ng)/2;
                if(mid*y>=a) ok = mid;
                else ng = mid;
            }
            ll len = x-ok;
            ok = y, ng = -1;
            while(ok-ng>1){
                ll mid = (ok+ng)/2;
                if(mid*len>=b) ok = mid;
                else ng = mid;
            }
            if(len*(y-ok)>=c) return true;
            swap(a,b);
            swap(b,c);
        }
        swap(x,y);
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    if(solve1(x,y,a,b,c) || solve2(x,y,a,b,c)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}