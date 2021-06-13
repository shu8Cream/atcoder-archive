/**
*    author:  shu8Cream
*    created: 13.06.2021 20:50:30
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

ll mod_pow(ll a, ll b, ll n){
    if(b==0) return 1;
    if(b%2!=0) return a * mod_pow(a, b-1, n) % n;
    else return mod_pow(a * a % n, b / 2, n) % n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b,c; cin >> a >> b >> c;
    if(c%2==0){
        if(abs(a)>abs(b)) cout << ">" << endl;
        else if(abs(a)<abs(b)) cout << "<" << endl;
        else cout << "=" << endl;
    }else{
        if(a>=0 && b>=0){
            if(abs(a)>abs(b)) cout << ">" << endl;
            else if(abs(a)<abs(b)) cout << "<" << endl;
            else cout << "=" << endl;
        }else if(a<=0 && b<=0){
            if(abs(a)>abs(b)) cout << "<" << endl;
            else if(abs(a)<abs(b)) cout << ">" << endl;
            else cout << "=" << endl;
        }else if(a>=0 && b<=0){
            cout << ">" << endl;
        }else{
            cout << "<" << endl;
        }
    }
}