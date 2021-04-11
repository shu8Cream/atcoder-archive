/**
*    author:  shu8Cream
*    created: 11.04.2021 20:46:32
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
    string a,b,c;
    cin >> a >> b >> c;
    set<char> s;
    rep(i,a.size()) s.insert(a[i]);
    rep(i,b.size()) s.insert(b[i]);
    rep(i,c.size()) s.insert(c[i]);
    if(s.size()>10){
        cout << "UNSOLVABLE" << "\n";
        return 0;
    }
    vi cnt(10); rep(i,10) cnt[i]=i;
    do{
        string ta = a, tb = b, tc = c;
        int i = 0;
        for(auto p : s){
            rep(j,a.size()) if(p==a[j]) ta[j]=char('0'+cnt[i]);
            rep(j,b.size()) if(p==b[j]) tb[j]=char('0'+cnt[i]);
            rep(j,c.size()) if(p==c[j]) tc[j]=char('0'+cnt[i]);
            i++;
        } 
        if(ta[0]=='0' || tb[0]=='0' || tc[0]=='0') continue;
        if(stoll(ta)+stoll(tb)==stoll(tc)){
            cout << ta << "\n";
            cout << tb << "\n";
            cout << tc << "\n";
            return 0;
        }
    }while(next_permutation(all(cnt)));
    cout << "UNSOLVABLE" << "\n";
}