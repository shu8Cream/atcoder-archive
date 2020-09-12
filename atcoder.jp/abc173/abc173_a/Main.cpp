#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    int i=0;
    while(1){
        i++;
        if(n<=i*1000){
            cout << i*1000-n << endl;
            return 0;
        }
    }
}