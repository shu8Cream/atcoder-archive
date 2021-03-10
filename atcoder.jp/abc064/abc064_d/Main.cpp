/**
*    author:  shu8Cream
*    created: 10.03.2021 09:27:54
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
    int n; string s;
    cin >> n >> s;
    deque<char> d;
    int tmp = 0, cur = 0;
    rep(i,n){
        if(s[i]=='('){
            tmp++;
        }else tmp--;
        d.push_back(s[i]);
        if(tmp<0){
            d.push_front('(');
            tmp++;
        }
    }
    while(tmp--) d.push_back(')');
    while(!d.empty()){
        cout << d.front();
        d.pop_front();
    }
    cout << endl;
}