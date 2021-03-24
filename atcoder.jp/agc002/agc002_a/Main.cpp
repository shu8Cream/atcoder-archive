/**
*    author:  shu8Cream
*    created: 24.03.2021 10:11:35
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
    ll a,b;
    cin >> a >> b;
    if(a*b<=0){
        cout << "Zero" << endl;
        return 0;
    }
    if(a<0 && b<0 && (b-a+1)%2==1){
        cout << "Negative" << endl;
        return 0;
    }
    cout << "Positive" << endl;
}