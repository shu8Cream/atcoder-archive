/**
*    author:  shu8Cream
*    created: 04.09.2021 21:21:30
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
    int q; cin >> q;
    deque<int> dq;
    multiset<int> s;
    rep(i,q){
        int c; cin >> c;
        if(c==1){
            int x; cin >> x;
            dq.push_back(x);
        }else if(c==2){
            if(s.empty()){
                cout << dq.front() << endl;
                dq.pop_front();
            }else{
                cout << *begin(s) << endl;
                s.erase(s.find(*begin(s)));
            }
        }else{
            while(!dq.empty()){
                s.insert(dq.front());
                dq.pop_front();
            }
        }
    }
}