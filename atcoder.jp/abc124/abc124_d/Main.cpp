/**
*    author:  shu8Cream
*    created: 31.05.2021 13:32:44
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
    int n,k; string s;
    cin >> n >> k >> s;
    vector<P> a;
    ll cnt = 1;
    rep(i,n-1){
        if(s[i]==s[i+1]) cnt++;
        else{
            a.push_back({s[i]-'0', cnt});
            cnt = 1;
        }
    }
    a.push_back({s[n-1]-'0',cnt});
    ll ans = 0, tmp = 0, zcnt = 0;
    int i = 0, j = 0;
    while(i<a.size()){
        if(zcnt<k && a[i].first==0){
            tmp+=a[i].second;
            zcnt++;
            chmax(ans,tmp);
            i++;
        }else if(zcnt<=k && a[i].first==1){
            tmp+=a[i].second;
            chmax(ans,tmp);
            i++;
        }else{
            tmp-=a[j].second;
            if(a[j].first==0) zcnt--;
            j++;
        }
    }
    cout << ans << endl;
}