/**
*    author:  shu8Cream
*    created: 16.12.2020 15:00:07
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int main(){
    double p;
    cin >> p;

    auto f = [&](double x){
        return x + p * pow(2,-x/1.5); 
    };
    auto df = [&](double x){
        return 1 + p * log(pow(2,(-1/1.5))) * pow(2,-x/1.5);
    };

    double l=0, r=p, mid;
    rep(i,10000){
        mid = (l+r)/2;
        if(df(mid)==0) break;
        else if(0 < df(mid)) r = mid;
        else l = mid;
    }
    printf("%.12lf\n", f(mid));
    return 0;
}