/**
*    author:  shu8Cream
*    created: 16.01.2021 21:48:29
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int mod = 998244353;
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

mint dp[5020][5020];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int H,W,k;
    cin >> H >> W >> k;
    vector<vector<char>> s(H, vector<char>(W,'.'));
    rep(i,k){
        int h,w;
        char c;
        cin >> h >> w >> c;
        h--; w--;
        s[h][w]=c;
    }

    dp[0][0]=mint(3).pow(H*W-k);

    mint inv3 = mint(3).inv();

    rep(i,H)rep(j,W){
        if(s[i][j]=='.'){
            dp[i][j+1]+=dp[i][j]*2*inv3;
            dp[i+1][j]+=dp[i][j]*2*inv3;
        }else if(s[i][j]=='X'){
            dp[i][j+1]+=dp[i][j];
            dp[i+1][j]+=dp[i][j];
        }
        else if(s[i][j]=='R') dp[i][j+1]+=dp[i][j];
        else if(s[i][j]=='D') dp[i+1][j]+=dp[i][j];
    }
    
    cout << dp[H-1][W-1] << endl;
}