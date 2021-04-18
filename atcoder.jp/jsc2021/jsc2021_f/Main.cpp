/**
*    author:  shu8Cream
*    created: 18.04.2021 12:10:02
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<typename T>
struct BIT{
public:
    int n; vector<T> a;
    BIT(int n_):n(n_),a(n+1,0){}

    void add(int idx, T x){
        idx++;
        if(idx<=0 || n<idx){ cerr << "Index error" << endl; return; }
        for(int i=idx; i<=n; i+=i&(-i)){
            a[i]+=x;
        }
    }

    T sum(int idx){
        T res = 0;
        idx++;
        if(idx<0 || n<idx){ cerr << "Index error" << endl; return 0; }
        if(idx==0) return 0;
        for(int i=idx; i>0; i-=(i&-i)){
            res+=a[i];
        }
        return res;
    }

    T sum(int l, int r){
        if(l==0) return sum(r-1);
        return sum(r-1)-sum(l-1);
    }
};

BIT<ll> a_cnt(440000);
BIT<ll> b_cnt(440000);
BIT<ll> a_sum(440000);
BIT<ll> b_sum(440000);

int a[220000];
int b[220000];

vi decomp;
ll ts[220000], xs[220000], ys[220000]; 

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,q,t,x,y;
    cin >> n >> m >> q;
    a_cnt.add(0,n);
    b_cnt.add(0,m);

    decomp.push_back(0);

    rep(i,q){
        cin >> ts[i] >> xs[i] >> ys[i];
        decomp.push_back(ys[i]);
    }

    sort(all(decomp));
    decomp.erase(unique(all(decomp)), decomp.end());

    rep(i,q){
        ys[i] = lower_bound(all(decomp), ys[i]) - decomp.begin();
    }

    ll ans = 0;
    rep(i,q){
        t = ts[i], x = xs[i], y = ys[i];
        if(t==1){
            int before = a[x];
            int after = y;
            int m = min(before, after), 
                M = max(before, after);
            ll diff = -b_sum.sum(m,M) 
                    + b_cnt.sum(m,M) * decomp[M] 
                    + (decomp[M]-decomp[m])*b_cnt.sum(0,m);
            if(before<=after) ans += diff;
            else ans-=diff;
            a_sum.add(before, -decomp[before]);
            a_cnt.add(before, -1);
            a_sum.add(after, decomp[after]);
            a_cnt.add(after, 1);
            a[x]=y;
        }
        if(t==2){
            int before = b[x];
            int after = y;
            int m = min(before, after), 
                M = max(before, after);
            ll diff = -a_sum.sum(m,M) 
                    + a_cnt.sum(m,M) * decomp[M] 
                    + (decomp[M]-decomp[m])*a_cnt.sum(0,m);
            if(before<=after) ans += diff;
            else ans-=diff;
            b_sum.add(before, -decomp[before]);
            b_cnt.add(before, -1);
            b_sum.add(after, decomp[after]);
            b_cnt.add(after, 1);
            b[x]=y;
        }
        cout << ans << endl;
    }
}