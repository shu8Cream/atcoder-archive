/**
*    author:  shu8Cream
*    created: 03.02.2021 11:34:06
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

bool solve(string s, string t){
    bool res = true;
    int n = s.size();
    map<char,char> m;
    rep(i,n){
        if(!m.count(t[i])){
            m[t[i]]=s[i];
        }else{
            if(m[t[i]]!=s[i]){
                res = false;
                break;
            }
        }
    }
    return res;
}

int main() {
    string s,t;
    cin >> s >> t;
    bool ans = solve(s,t) && solve(t,s);
    cout << (ans ? "Yes" : "No") << endl;
}