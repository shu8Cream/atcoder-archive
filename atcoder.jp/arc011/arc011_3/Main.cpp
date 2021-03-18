/**
*    author:  shu8Cream
*    created: 18.03.2021 18:55:32
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

bool f(string s1, string s2){
    int l = s1.size();
    int cnt = 0;
    rep(i,l) if(s1[i]!=s2[i]) cnt++;
    return (cnt==1);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string fi,la;
    int n;
    cin >> fi >> la >> n;
    int len = fi.size();
    vector<string> s(n+2);
    s[0]=fi; s[1]=la;
    rep(i,n) cin >> s[i+2];
    vvi to(n+2);
    rep(i,n+2){
        for(int j=i+1; j<n+2; j++){
            if(f(s[i],s[j])){
                to[i].push_back(j);
                to[j].push_back(i);
            }
        }
    }
    vi dist(n+2,-1), prev(n+2);
    queue<int> q;
    q.push(0);
    dist[0]=0;
    while(!q.empty()){
        int nv = q.front();
        q.pop();
        for(auto p : to[nv]){
            if(dist[p]!=-1) continue;
            dist[p]=dist[nv]+1;
            prev[p]=nv;
            q.push(p);
        }
    }
    if(fi==la){
        cout << 0 << endl;
        cout << fi << endl;
        cout << la << endl;
        return 0;
    }
    if(dist[1]==-1){
        cout << -1 << endl;
        return 0;
    }
    vector<string> ans;
    ans.push_back(s[1]);
    int tmp = 1;
    while(1){
        if(s[0]==s[prev[tmp]]) break;
        ans.push_back(s[prev[tmp]]);
        tmp = prev[tmp];
    }
    ans.push_back(s[0]);
    cout << dist[1]-1 << endl;
    rep(i,dist[1]+1) cout << ans[dist[1]-i] << endl;
}