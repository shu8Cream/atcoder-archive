/**
*    author:  shu8Cream
*    created: 20.12.2020 12:36:18
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

const int mod = 1000000007;

struct mint{
    ll x;
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

void rot(vvi& a){
    int h = a.size(), w = a[0].size();
    vvi pre(w,vi(h));
    swap(a,pre);
    rep(i,w)rep(j,h) a[i][j]=pre[h-1-j][i];
}

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vvi a(h,vi(w));
    rep(i,h)rep(j,w) if(s[i][j]=='.') a[i][j]=1;

    //2の累乗の前計算
    int n = h*w;
    vector<mint> two(n+1,1);
    rep(i,n) two[i+1]=two[i]*2;

    int k = 0; //散らかってないマス数
    vvi ks = a; //見えるマス数を計算用
    rep(i,h)rep(j,w) k+=a[i][j];

    rep(ri,4){
        vvi d(h,vi(w));
        rep(i,h){
            rep(j,w-1){
                if(a[i][j]) d[i][j]++;
                else d[i][j]=0;
                if(a[i][j+1]) ks[i][j+1]+=d[i][j];
                d[i][j+1]=d[i][j];
            }
        }
        rot(a);
        rot(ks);
        swap(h,w);
    }

    mint ans = two[k]*n;
    rep(i,h)rep(j,w){
        int x = k-ks[i][j];
        ans-=two[x];
    }
    cout << ans << endl;
}