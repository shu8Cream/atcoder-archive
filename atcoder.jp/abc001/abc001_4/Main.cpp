/**
*    author:  shu8Cream
*    created: 04.04.2021 19:08:21
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
    int n; cin >> n;
    vector<P> a;
    rep(j,n){
        string s;
        cin >> s;
        int str = 0, grl = 0;
        str = stoi(s.substr(0,4));
        grl = stoi(s.substr(5,4));
 
        str = str - str%5;
        grl = (grl + 4) / 5 * 5;
 
        if(grl%100==60) grl = grl/100*100 + 100;
        a.push_back({str,grl});
    }
    sort(all(a));
    int str = a[0].first;
    int grl = a[0].second;
    rep(i,n-1){
        if(grl < a[i+1].first){
            cout << setw(4) << setfill('0') << str << "-";
            cout << setw(4) << setfill('0') << grl << endl;
            str = a[i+1].first;
            grl = a[i+1].second;
        }else{
            grl = max(grl, a[i+1].second);
        }
    }
    cout << setw(4) << setfill('0') << str << "-";
    cout << setw(4) << setfill('0') << grl << endl;
}