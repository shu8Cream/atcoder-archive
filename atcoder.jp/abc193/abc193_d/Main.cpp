/**
*    author:  shu8Cream
*    created: 27.02.2021 20:11:12
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int score(string s, int n){
    int res = 0;
    vi c(9);
    rep(i,4) c[s[i]-'1']++;
    c[n-1]++;
    rep(i,9){
        res+=(i+1)*pow(10,c[i]);
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll k;
    string s,t;
    cin >> k >> s >> t;
    vector<ll> card(9,k);
    rep(i,4){
        card[s[i]-'1']--;
        card[t[i]-'1']--;
    }
    ll cnt = 0;
    rep(i,9)rep(j,9){
        if(card[i]==0 || card[j]==0) continue;
        if(i==j && card[i]==1) continue;
        if(i!=j && score(s,i+1)>score(t,j+1)){
            cnt+=card[i]*card[j];
        }
        if(i==j && score(s,i+1)>score(t,j+1)){
            cnt+=card[i]*(card[j]-1);
        }
    }
    ll con = (9*k-8)*(9*k-9);
    double ans = (double)cnt/con;
    printf("%.10lf\n", ans);
}