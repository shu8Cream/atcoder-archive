#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    rep(i,10)rep(j,10){
        if(n==i*j) {
            cout<<"Yes"<<endl;
            return 0;
        } 
    }
    cout << "No" << endl;
}