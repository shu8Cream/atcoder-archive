/**
*    author:  shu8Cream
*    created: 01.03.2021 19:14:17
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
    int x1,y1,r,x2,y2,x3,y3;
    cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;
    bool rok = true;
    bool bok = true;
    if(x2<=x1 && x1<=x3 && y2<=y1+r && y1+r<=y3){
        if(x2<=x1 && x1<=x3 && y2<=y1-r && y1-r<=y3){
            if(x2<=x1+r && x1+r<=x3 && y2<=y1 && y1<=y3){
                if(x2<=x1-r && x1-r<=x3 && y2<=y1 && y1<=y3){
                    rok = false;
                }
            }
        }
    }
    if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)<=r*r){
        if((x2-x1)*(x2-x1)+(y3-y1)*(y3-y1)<=r*r){
            if((x3-x1)*(x3-x1)+(y2-y1)*(y2-y1)<=r*r){
                if((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)<=r*r){
                    bok = false;
                }
            }
        }
    }

    cout << (rok ? "YES" : "NO") << endl;
    cout << (bok ? "YES" : "NO") << endl;
}