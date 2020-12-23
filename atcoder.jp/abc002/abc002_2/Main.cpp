/**
*    author:  shu8Cream
*    created: 23.12.2020 20:13:51
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)

const vector<char> boin = {'a', 'i', 'u', 'e', 'o'};

int main() {
    string w;
    cin >> w;
    string ans;
    rep(i,w.size()){
        bool flag = false;
        rep(j,5){
            if(w[i]==boin[j]) flag=true;
        }
        if(!flag) ans+=w[i];
    }
    cout << ans << endl;
}