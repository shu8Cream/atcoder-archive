/**
*    author:  shu8Cream
*    created: 27.03.2021 21:36:38
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

const ll INF = 1e11;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi left_most(n+1,INF), right_most(n+1,-INF);
    vi colors;
    rep(i,n){
        ll x,c;
        cin >> x >> c;
        colors.push_back(c);
        left_most[c] = min(left_most[c],x);
        right_most[c] = max(right_most[c],x);
    }
    sort(all(colors));
    colors.erase(unique(all(colors)), colors.end());
    // rep(i,colors.size()) cout << colors[i] << endl;

    ll l = 0, r = 0, lpos = 0, rpos = 0;
    for(auto c : colors){
        // cout << l << " " << r << endl;
        // cout << lpos << " " << rpos << endl;
        ll nlpos = left_most[c], nrpos = right_most[c];
        ll nl = min(l + abs(lpos - nrpos) + abs(nrpos - nlpos),
                    r + abs(rpos - nrpos) + abs(nrpos - nlpos));
        ll nr = min(l + abs(lpos - nlpos) + abs(nrpos - nlpos),
                    r + abs(rpos - nlpos) + abs(nrpos - nlpos));
        lpos = nlpos; rpos = nrpos;
        l = nl; r = nr;
    }

    ll ans = min(l + abs(lpos), r + abs(rpos));
    cout << ans << endl;
}