/**
*    author:  shu8Cream
*    created: 30.01.2021 23:19:25
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

struct BIT {
    private:
    vector<int> bit;
    int N;
    
    public:
    BIT(int size) {
        N = size;
        bit.resize(N + 1);
    }
    
    void add(int a, int w) {
        for (int x = a; x <= N; x += x & -x) bit[x] += w;
    }

    int sum(int a) {
        int ret = 0;
        for (int x = a; x > 0; x -= x & -x) ret += bit[x];
        return ret;
    }
 };

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n);
    rep(i,n){
        cin >> a[i];
        a[i]++;
    }
    ll ans = 0;
    BIT b(n);
    rep(i,n){
        ans+=i-b.sum(a[i]);
        b.add(a[i],1);
    }
    cout << ans << endl;
    rep(i,n-1){
        ans+=n-1-2*(a[i]-1);
        cout << ans << endl;
    }
}