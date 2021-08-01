/**
*    author:  shu8Cream
*    created: 01.08.2021 23:34:30
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
    int q,cmd; cin >> q;
    priority_queue<ll, vi, greater<ll>> pq;
    ll x, cnt = 0;
    while(q--){
        cin >> cmd;
        if(cmd==1){
            cin >> x;
            pq.push(x-cnt);
        }
        if(cmd==2){
            cin >> x;
            cnt += x;
        }
        if(cmd==3){
            cout << pq.top()+cnt << endl;
            pq.pop();
        }
    }
}