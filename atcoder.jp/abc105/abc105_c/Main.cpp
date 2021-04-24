/**
*    author:  shu8Cream
*    created: 01.03.2021 21:31:50
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
    int n;
    cin >> n;
    string minus = "";
    while(n!=0){
        int tmp = n%2;
        if(tmp<0) tmp+=2;
        n=(n-tmp)/(-2);
        minus+=(char)('0'+tmp);
    }
    reverse(all(minus));
    if(minus=="") minus="0";
    cout << minus << endl;
}