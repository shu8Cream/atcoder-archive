/**
*    author:  shu8Cream
*    created: 29.03.2021 22:01:28
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

template <typename T>
vector<T> divisor(T n) {
    vector<T> ret;
    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vi a(n);
    int sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    auto d = divisor(sum);

    vi r(n);
    int ans = 0;
    rep(i,d.size()){
        rep(j,n) r[j]=a[j]%d[i];
        sort(all(r));
        vi up(n+1),down(n+1);
        rep(j,n) up[j+1]=up[j]+d[i]-r[j];
        rep(j,n) down[j+1]=down[j]-r[j];
        rep(j,n+1){
            if(-down[j]>k) break;
            if(-down[j]==up[n]-up[j]){
                ans=max(ans,d[i]);
                break;
            }
        }
    }
    cout << ans << endl;
}