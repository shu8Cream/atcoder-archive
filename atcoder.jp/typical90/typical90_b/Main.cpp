/**
*    author:  shu8Cream
*    created: 31.03.2021 10:13:14
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
    if(n%2==1) return 0;
    vector<string> akk,ans;
    int half = n/2;
    string kakko;
    rep(i,half) kakko+='(';
    rep(i,half) kakko+=')';
    do{
        akk.push_back(kakko);
    }while(next_permutation(all(kakko)));
    // rep(i,akk.size()) cout << akk[i] << endl;
    rep(i,akk.size()){
        bool ok = true;
        stack<char> st;
        rep(j,n){
            if(st.empty() && akk[i][j]=='(') st.push('(');
            else if(st.empty() && akk[i][j]==')'){
                ok = false;
                break;
            }else if(st.top()=='(' && akk[i][j]==')') st.pop();
            else if(st.top()=='(' && akk[i][j]=='(') st.push('(');
        } 
        if(ok) ans.push_back(akk[i]);
    }
    rep(i,ans.size()) cout << ans[i] << endl;
}