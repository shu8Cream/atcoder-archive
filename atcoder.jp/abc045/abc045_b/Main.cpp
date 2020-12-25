/**
*    author:  shu8Cream
*    created: 25.12.2020 20:46:22
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)

int main() {
    string sa,sb,sc;
    cin >> sa >> sb >> sc;
    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    reverse(sc.begin(), sc.end());
    char now = sa[sa.size()-1];
    sa.pop_back();
    char ans;
    while(1){
        if(now=='a'){
            if(sa.empty()){
                ans='A';
                break;
            }
            now=sa[sa.size()-1];
            sa.pop_back();
        }
        if(now=='b'){
            if(sb.empty()){
                ans='B';
                break;
            }
            now=sb[sb.size()-1];
            sb.pop_back();
        }
        if(now=='c'){
            if(sc.empty()){
                ans='C';
                break;
            }
            now=sc[sc.size()-1];
            sc.pop_back();
        }
    }
    cout << ans << endl;
}