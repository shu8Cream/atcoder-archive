/**
*    author:  shu8Cream
*    created: 02.05.2021 10:38:03
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    int n = s.size();
    string ans = "";
    int rcnt = 0;
    deque<char> d;
    rep(i,n){
        if(s[i]=='R'){
            rcnt++;
            continue;
        }
        if(rcnt%2==0) d.push_back(s[i]);
        else d.push_front(s[i]);
    }

    stack<char> st;
    rep(i,n-rcnt){
        char p = d.front(); d.pop_front();
        if(!st.empty()){
            if(st.top()==p) st.pop();
            else st.push(p);
        }else st.push(p);
    }
    while(!st.empty()){
        char v = st.top(); st.pop();
        ans+=v;
    }
    if(rcnt%2==0) reverse(all(ans));
    cout << ans << endl;
}