/**
*    author:  shu8Cream
*    created: 10.04.2021 22:39:31
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

vi memo(1001001,-1);

int tri(int n){
    if(n==1) return memo[n]=0;
    else if(n==2) return memo[n]=0;
    else if(n==3) return memo[n]=1;
    else{
        if(memo[n]!=-1) return memo[n];
        return memo[n]=((tri(n-1)+tri(n-2))%10007+tri(n-3))%10007;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << tri(n) << endl;
}