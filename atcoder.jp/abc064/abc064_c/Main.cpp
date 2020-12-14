/**
*    author:  shu8Cream
*    created: 14.12.2020 22:26:16
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    
    int over3200=0;
    set<int> s;
    rep(i,n){
        if(a[i]>=3200){
            over3200++;
            continue;
        }
        s.insert(a[i]/400);
    }

    if(s.size()!=0) cout << s.size() << " " << s.size()+over3200 << endl;
    else cout << 1 << " " << over3200 << endl;
}