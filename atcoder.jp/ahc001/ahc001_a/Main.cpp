/**
*    author:  shu8Cream
*    created: 06.03.2021 11:57:11
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

ll score(vector<tuple<int,int,int>> IN, vector<tuple<int,int,int,int,int>> OUT){
    double n = IN.size();
    double res = 0;
    rep(i,n){
        ll x,y; double r;
        tie(x,y,r)=IN[i];
        ll a,b,c,d,idx;
        tie(idx,a,b,c,d)=OUT[i];
        double s = (c-a)*(d-b);
        double tt = (1-min(r,s)/max(r,s))*(1-min(r,s)/max(r,s));
        double nsc = (1-tt);
        res+=round(nsc*1e9);
    }
    res/=n;
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<tuple<int,int,int>> xyr(n),xyr2(n),IN(n);
    vector<tuple<int,int,int,int,int>> ans(n),ans2(n);
    rep(i,n){
        int x,y,r;
        cin >> x >> y >> r;
        IN[i]={x,y,r};
        xyr[i]={x,y,i};
        xyr2[i]={y,x,i};
    }
    
    // 縦長
    int prex = -1, prey = 0, prer = 0;
    sort(all(xyr));
    rep(i,n){
        int x,y,r;
        tie(x,y,r)=xyr[i];
        //printf("%d %d %d\n", x, y, r);
    }
    rep(i,n){
        int x,y,r;
        tie(x,y,r)=xyr[i];
        int ppx=0;
        if(prex==x){
            int a,b,c,d,e;
            tie(e,a,b,c,d)=ans[i-2];
            if(a!=x){
                ppx=c;
                ans[i-1]={prer,ppx,0,x+1,prey+1};
            }else ans[i-1]={prer,ppx,prey,x+1,prey+1};
            ans[i]={r,ppx,prey+1,x+1,10000}; 
            //printf("%d %d %d %d\n", x,prey,x+1,prey+1);
            //printf("%d %d %d %d\n", x,y,x+1,y+1);
        }else{
            ans[i]={r,prex+1, 0, x+1, 10000};
            //printf("%d %d %d %d\n", prex, 0, x+1, 10000);
        }
        prex=x;
        prey=y;
        prer=r;
    }
    rep(i,n){
        int r,a,b,c,d;
        tie(r,a,b,c,d)=ans[i];
        //printf("%d %d %d %d\n", a,b,c,d);
    }
    sort(all(ans));
    rep(i,n){
        int r,a,b,c,d;
        tie(r,a,b,c,d)=ans[i];
        //fprintf(fp, "%d %d %d %d\n", a,b,c,d);
        //printf("%d %d %d %d\n", a,b,c,d);
    }
    ll scr = score(IN,ans);
    cerr << scr << endl;

//*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*//
    // 横長
    prex = 0, prey = 0, prer = 0;
    sort(all(xyr2));
    rep(i,n){
        int x,y,r;
        tie(x,y,r)=xyr2[i];
        //printf("%d %d %d\n", y, x, r);
    }
    rep(i,n){
        int x,y,r;
        tie(x,y,r)=xyr2[i];
        int ppx=0;
        if(prex==x){
            int a,b,c,d,e;
            tie(e,a,b,c,d)=ans2[i-2];
            if(b!=x){
                ppx=d;
                ans2[i-1]={prer,0,ppx,prey+1,x+1};
            }else ans2[i-1]={prer,prey,ppx,10000,x+1};
            ans2[i]={r,prey+1,ppx,y+1,x+1}; 
            //printf("%d %d %d %d\n", x,prey,x+1,prey+1);
            //printf("%d %d %d %d\n", x,y,x+1,y+1);
        }else{
            ans2[i]={r,0, prex+1, 10000, x+1};
            //printf("%d %d %d %d\n", prex, 0, x+1, 10000);
        }
        prex=x;
        prey=y;
        prer=r;
    }
    rep(i,n){
        int r,a,b,c,d;
        tie(r,a,b,c,d)=ans2[i];
        //printf("%d %d %d %d\n", a,b,c,d);
    }
    sort(all(ans2));
    rep(i,n){
        int r,a,b,c,d;
        tie(r,a,b,c,d)=ans2[i];
        //fprintf(fp, "%d %d %d %d\n", a,b,c,d);
        //printf("%d %d %d %d\n", a,b,c,d);
    }
    ll scr2 = score(IN,ans2);
    cerr << scr2 << endl;

    if(scr>scr2){
        rep(i,n){
            int r,a,b,c,d;
            tie(r,a,b,c,d)=ans[i];
            //fprintf(fp, "%d %d %d %d\n", a,b,c,d);
            printf("%d %d %d %d\n", a,b,c,d);
        }
    }else{
        rep(i,n){
            int r,a,b,c,d;
            tie(r,a,b,c,d)=ans2[i];
            //fprintf(fp, "%d %d %d %d\n", a,b,c,d);
            printf("%d %d %d %d\n", a,b,c,d);
        }
    }
}