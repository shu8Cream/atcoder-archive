/**
*    author:  shu8Cream
*    created: 03.01.2021 15:46:23
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

mint f(int n, int a){
    mint res = 1;
    rep(i,a){
        res*=n;
        n--;
        res/=i+1;
    }
    return res;
}

ll mod_pow(ll a, ll b, ll n){
    if(b==0) return 1;
    if(b%2!=0) return a * mod_pow(a, b-1, n) % n;
    else return mod_pow(a * a % n, b / 2, n) % n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin >> n >> a >> b;
    mint ans = 2;
    ans=mod_pow(2,n,mod);
    ans-=1;
    ans-=f(n,a);
    ans-=f(n,b);
    cout << ans << endl;
}