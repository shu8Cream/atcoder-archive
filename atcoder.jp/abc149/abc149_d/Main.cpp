#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
    int n,k,r,s,p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    int ans=0;
    rep(i,k){
        bool f = false;
        for(int j=i; j<n; j+=k){
            if(j-k>=0 && t[j]==t[j-k] && f) f=false;
            else{
                f=true;
                if(t[j]=='r') ans+=p;
                if(t[j]=='s') ans+=r;
                if(t[j]=='p') ans+=s;
            }
        }
    }
    cout << ans << endl;
}