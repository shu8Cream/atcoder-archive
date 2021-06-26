/**
*    author:  shu8Cream
*    created: 26.06.2021 20:46:10
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    set<ll> s;
    vi L(n),R(n);
    rep(i,n){
        int t; ll l,r;
        cin >> t >> l >> r;
        l = 2*l-1;
        r = 2*r-1;
        if(t==1){
            s.insert(l);
            s.insert(r+1);
            L[i] = l;
            R[i] = r;
        }
        if(t==2){
            s.insert(l);
            s.insert(r);
            L[i] = l;
            R[i] = r-1;
        }
        if(t==3){
            s.insert(l+1);
            s.insert(r+1);
            L[i] = l+1;
            R[i] = r;
        }
        if(t==4){
            s.insert(l+1);
            s.insert(r);
            L[i] = l+1;
            R[i] = r-1;
        }
    }
    vvi vec(n,vi(s.size()+5));
    int cnt = 0;
    for(auto p : s){
        rep(i,n){
            if(L[i]==p) vec[i][cnt]++;
            if(R[i]==p) vec[i][cnt]--;
        }
        cnt++;
    }
    rep(i,n)rep(j,s.size()+5){
        if(0<i) vec[i][j]+=vec[i][j-1];
    }
    int ans = 0;
    rep(i,n)for(int j=i+1; j<n; j++){
        // cout << L[i] << " " << R[i] << endl;
        // cout << L[j] << " " << R[j] << endl;
        if(R[j]<L[i] || R[i]<L[j]) continue;
        ans++;
    }
    cout << ans << endl;
}