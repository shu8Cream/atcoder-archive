/**
*    author:  shu8Cream
*    created: 20.03.2021 00:02:05
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a),q(b),r(c);
    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    rep(i,c) cin >> r[i];
    sort(all(p));
    sort(all(q));
    sort(all(r));
    stack<ll> rst, bst, cst;
    rep(i,x){
        rst.push(p.back());
        p.pop_back();
    }
    rep(i,y){
        bst.push(q.back());
        q.pop_back();
    }
    while(!r.empty()){
        if(rst.empty() && bst.empty()) break;
        if(rst.empty() && r.back()>bst.top()){
            bst.pop();
            cst.push(r.back());
            r.pop_back();
        }else if(bst.empty() && r.back()>rst.top()){
            rst.pop();
            cst.push(r.back());
            r.pop_back();
        }else if(!rst.empty() && !bst.empty()){
            if(rst.top()<=bst.top() && r.back()>rst.top()){
                rst.pop();
                cst.push(r.back());
                r.pop_back();
            }else if(bst.top()<rst.top() && r.back()>bst.top()){
                bst.pop();
                cst.push(r.back());
                r.pop_back();
            }else break;
        }else break;
    }
    ll ans = 0;
    while(!rst.empty()) { ans+=rst.top(); rst.pop(); }
    while(!bst.empty()) { ans+=bst.top(); bst.pop(); }
    while(!cst.empty()) { ans+=cst.top(); cst.pop(); }
    cout << ans << endl;
}