/**
*    author:  shu8Cream
*    created: 18.02.2021 17:27:07
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x,y; string w;
    cin >> x >> y >> w;
    x--; y--;
    vector<string> c(9);
    rep(i,9) cin >> c[i];
    string ans;
    int dx,dy;
    if(w == "R"){
        dx = 1; dy = 0;
    }else if(w == "L"){
        dx = -1; dy = 0;
    }else if(w == "U"){
        dx = 0; dy = -1;
    }else if(w == "D"){
        dx = 0; dy = 1;
    }else if(w == "RU"){
        dx = 1; dy = -1;
    }else if(w == "RD"){
        dx = 1; dy = 1;
    }else if(w == "LU"){
        dx = -1; dy = -1;
    }else if(w == "LD"){
        dx = -1; dy = 1;
    }
    ans += c[y][x];
    
    rep(i,3){
        int cx=x, cy=y;
        cx+=dx; cy+=dy;
        if(cx<0 || cx>=9) dx*=-1;
        if(cy<0 || cy>=9) dy*=-1;
        x+=dx; y+=dy;
        ans+=c[y][x];
    }
    cout << ans << endl;
}