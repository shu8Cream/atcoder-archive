/**
*    author:  shu8Cream
*    created: 24.02.2021 21:31:21
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int mod = 1000000007;
//const int mod = 998244353;
struct mint{
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi t(n),a(n);
    int tm=0,am=0;
    rep(i,n){
        cin >> t[i];
        tm=max(tm,t[i]);
    }
    rep(i,n){
        cin >> a[i];
        am=max(am,a[i]);
    }
    vi m(n);
    m[0]=t[0];
    m[n-1]=a[n-1];
    bool ok = true;
    if(tm!=am) ok = false;
    rep(i,n-2){
        if(t[i]!=t[i+1]){
            if(m[i+1]!=t[i+1] && m[i+1]!=0) ok = false;
            m[i+1]=t[i+1];
        }
    }
    if(t[n-2]!=t[n-1]){
        if(m[n-2]!=t[n-2] && m[n-2]!=0) ok = false;
        m[n-2]=t[n-2];
    }
    rep(i,n){
        if(m[i]==0) continue;
        if(a[i]<m[i]) ok = false;
    }
    rep(i,n-2){
        if(a[n-1-i]!=a[n-2-i]){
            if(m[n-2-i]!=a[n-2-i] && m[n-2-i]!=0) ok = false;
            m[n-2-i]=a[n-2-i];
        }
    }
    if(a[0]!=a[1]){
        if(m[1]!=a[1] && m[1]!=0) ok = false;
        m[1]=a[1];
    }
    mint ans = 1;
    ll pre=m[0], now=m[0];
    bool asc = true;
    int cnt=0;
    rep(i,n){
        if(m[i]!=0){
            pre=now;
            now=m[i];
            if(cnt>0){
                if(pre<=now){
                    while(cnt--) ans*=pre;
                }else{
                    while(cnt--) ans*=now;
                }
            }
            cnt=0;
        }else cnt++;
    }
    if(!ok) cout << 0 << endl;
    else cout << ans << endl;
}
