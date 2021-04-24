/**
*    author:  shu8Cream
*    created: 24.04.2021 20:47:33
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
    int n,q; string s;
    cin >> n >> s >> q;
    int cnt = 0;
    rep(i,q){
        int t,a,b;
        cin >> t >> a >> b;
        a--; b--;
        if(t==1){
            if(cnt%2==0) swap(s[a],s[b]);
            else {
                if(0<=a && a<n) a+=n;
                else a-=n;
                if(0<=b && b<n) b+=n;
                else b-=n;
                swap(s[a],s[b]);
            }
        }else{
            cnt++;
        }
    }
    if(cnt%2==1){
        string f = s.substr(0,n);
        string b = s.substr(n,n);
        s = b + f;
    }
    cout << s << endl;
}