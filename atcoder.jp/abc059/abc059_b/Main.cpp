/**
*    author:  shu8Cream
*    created: 07.03.2021 23:48:53
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
    string a,b;
    cin >> a >> b;
    int la = a.size();
    int lb = b.size(); 
    string ans;
    if(a==b){
        cout << "EQUAL" << endl;
        return 0;
    }
    if(la>lb) ans = "GREATER";
    else if(la<lb) ans = "LESS";
    else{
        rep(i,la){
            if(a[i]-'0'>b[i]-'0'){
                ans = "GREATER";
                break;
            }else if(a[i]-'0'<b[i]-'0'){
                ans = "LESS";
                break;
            }
        }
    }
    cout << ans << endl;
}