/**
*    author:  shu8Cream
*    created: 16.12.2020 00:23:12
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

vi Zalgo(string str){
    int n = str.size();
    vi a(n,0);
    int from = -1, last = -1;
    vi ind;
    for(int i=1; i<n; i++){
        int &same=a[i];
        if(from != -1){
            same = min(a[i-from], last - i);
            same = max(0, same);
        }
        while(i + same < n && str[same]==str[i+same]) same++;
        if(last < i+same){
            last = i + same;
            from = i;
        }
        if(i<same) ind.push_back(i);
    }
    a[0]=0;
    rep(i,ind.size()) a[ind[i]]=0;
    return a;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans=0;
    rep(i,n){
        auto a = Zalgo(s.substr(i,n-i));
        rep(j,a.size()) ans=max(ans, a[j]);
    }

    cout << ans << endl;
}