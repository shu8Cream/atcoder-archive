/**
*    author:  shu8Cream
*    created: 09.08.2021 13:17:04
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vi r,b,g;
    rep(i,2*n){
        ll a; string c; 
        cin >> a >> c;
        if(c=="R") r.push_back(a);
        if(c=="B") b.push_back(a);
        if(c=="G") g.push_back(a);
    }
    if(r.size()%2==0 && g.size()%2==0){
        cout << 0 << endl;
        return 0;
    }

    vi odd1, odd2, even;
    if(r.size()%2==0){
        even = r;
        odd1 = g;
        odd2 = b;
    }else if(g.size()%2==0){
        even = g;
        odd1 = r;
        odd2 = b;
    }else{
        even = b;
        odd1 = g;
        odd2 = r;
    }

    sort(all(even));
    sort(all(odd1));
    sort(all(odd2));

    ll ans = 8e18;
    rep(i,odd1.size()){
        ll itr = lower_bound(all(odd2), odd1[i]) - odd2.begin();
        if(itr<0) itr = 0;
        if(itr>=odd2.size()) itr = odd2.size()-1;
        chmin(ans,abs(odd1[i]-odd2[itr]));
        if(itr-1>=0) chmin(ans,abs(odd1[i]-odd2[itr-1]));
    }

    vector<P> o1,o2;
    if(!even.empty()){
        rep(i,odd1.size()){
            ll itr = lower_bound(all(even), odd1[i]) - even.begin();
            if(itr<0) itr = 0;
            if(itr>=even.size()) itr = even.size()-1;
            o1.push_back({abs(odd1[i]-even[itr]),itr});
            if(itr-1>=0) o1.push_back({abs(odd1[i]-even[itr-1]),itr-1});
        }
    }
    if(!even.empty()){
        rep(i,odd2.size()){
            ll itr = lower_bound(all(even), odd2[i]) - even.begin();
            if(itr<0) itr = 0;
            if(itr>=even.size()) itr = even.size()-1;
            o2.push_back({abs(odd2[i]-even[itr]),itr});
            if(itr+1>=0) o2.push_back({abs(odd2[i]-even[itr-1]),itr-1});
        }
    }
    sort(all(o1)); sort(all(o2));
    vi sum;
    if(!o1.empty() && !o2.empty()){
        rep(i,min(5,(int)o1.size()))rep(j,min(5,(int)o2.size())){
            sum.push_back(o1[i].first+o2[j].first);
        }
    }
    sort(all(sum));
    if(!sum.empty()) chmin(ans,sum[0]);
    cout << ans << endl;

}