/**
*    author:  shu8Cream
*    created: 14.11.2021 15:56:28
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll INF = 8e18;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
cout << H << " ";
debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std::chrono;
inline double get_time_sec(void){
    return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

const vi dx = {1,0,-1,0};
const vi dy = {0,1,0,-1};

int n = 1000;
int field[1000][1000];
int timeS = 1e9;
vvi to(1000);

struct locate{
    int x,y;
    bool operator<(const locate &other) const {
        return abs(x-400) + abs(y-400) < abs(other.x-400) + abs(other.y-400);
    }
    bool operator==(const locate &other) const {
        return x==other.x && y==other.y;
    }
};

vector<pair<locate,locate>> order(n);
void INPUT(){
    field[400][400] = 2000;
    rep(i,n){
        locate S,G;
        cin >> S.x >> S.y >> G.x >> G.y;
        field[S.x][S.y] = i+1;
        field[G.x][G.y] = -(i+1);
        order[i] = {S,G};
    }
}

ll score(){
    ll res = 100000000;
    res = round((double)res/(1000+timeS));
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    INPUT();

    double start = get_time_sec();
    double end = get_time_sec();

    vector<P> ans(102);
    ans[0] = {400,400};
    ans[101] = {400,400};
    vi ans2(50);


    int tu = 0;
    vi ind(1000);
    rep(i,1000) ind[i] = i+1;

    vector<pair<pair<locate,locate>, int>> II(1000);
    rep(i,n){
        II[i] = {order[i],i};
    } 
    sort(all(II));
    rep(i,1000) ind[i] = II[i].second+1;
    // sort(all(order));

    while(end-start<1.95){
        end = get_time_sec();
        vi nind(100);
        rep(i,100) nind[i] = ind[i];
        tu++;
        if(tu!=0){
            std::random_device get_rand_dev;
            std::mt19937 get_rand_mt( get_rand_dev() ); // seedに乱数を指定
            std::shuffle(all(nind), get_rand_mt);
        }
        vector<P> tmpAns(102);
        tmpAns[0] = {400,400};
        tmpAns[101] = {400,400};
        P nowPos = {400,400};
        rep(i,50){
            // t += abs(nowPos.first-order[nind[i]-1].first.x) + abs(nowPos.second - order[nind[i]-1].first.y);
            nowPos = {order[nind[i]-1].first.x, order[nind[i]-1].first.y};
            tmpAns[(i+1)*2-1] = {order[nind[i]-1].first.x, order[nind[i]-1].first.y};
            // t += abs(nowPos.first-order[nind[i]-1].second.x) + abs(nowPos.second - order[nind[i]-1].second.y);
            nowPos = {order[nind[i]-1].second.x, order[nind[i]-1].second.y};
            tmpAns[(i+1)*2] = {order[nind[i]-1].second.x, order[nind[i]-1].second.y};
        }
        // t += abs(nowPos.first-400) + abs(nowPos.second - 400);

        vector<P> root(100);
        rep(i,50){
            root[i*2] = {order[nind[i]-1].first.x, order[nind[i]-1].first.y};
            root[i*2+1] = {order[nind[i]-1].second.x, order[nind[i]-1].second.y};
        }
        vector<bool> passed(100);
        int now = 0;
        vi ss; ss.push_back(0);
        while(1){
            int next = -1;
            int tmp = 1e9;
            passed[now] = 1;
            rep(i,100){
                if(passed[i]) continue;
                if(i%2==1 && !passed[i-1]) continue;
                int a = abs(root[now].first - root[i].first) + abs(root[now].second - root[i].second);
                if(a<tmp){
                    chmin(tmp,a);
                    next = i;
                }
            }
            if(next==-1) break;
            ss.push_back(next);
            now = next;
        }


        for(int i=1; i<101; i++){
            tmpAns[i] = root[ss[i-1]];
        }

        int t = 0;
        rep(i,100){
            t += abs(tmpAns[i].first-tmpAns[i+1].first) + abs(tmpAns[i].second-tmpAns[i+1].second);
        }
        t+=abs(tmpAns[100].first-400) + abs(tmpAns[100].second-400);

        if(timeS>t){
            chmin(timeS,t);
            ans = tmpAns;
            rep(i,50) ans2[i] = nind[i];
        }
    }
    ll p = score();
    debug(p);

    cout << 50 << " ";
    rep(i,50) cout << ans2[i] << (i==49 ? "\n" : " ");
    cout << 102 << " ";
    rep(i,102) cout << ans[i].first << " " << ans[i].second << (i==101 ? "\n" : " ");
}