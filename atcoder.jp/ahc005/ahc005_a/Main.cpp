/**
*    author:  shu8Cream
*    created: 07.08.2021 15:53:58
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

const int INF = 1001001001;
const vi di = {1,0,-1,0};
const vi dj = {0,1,0,-1};
const vs dir = {"D", "R", "U", "L"};

int n,si,sj;
vs c;

void input(){
    cin >> n >> si >> sj;
    c.resize(n);
    rep(i,n) cin >> c[i];
}

int costCalc(vector<P> &crossPoint, int s, int g){
    int res = 0;
    auto [nowi, nowj] = crossPoint[s];
    auto [gi,gj] = crossPoint[g];
    queue<P> q;
    q.push({nowi,nowj});
    vvi prev(n,vi(n,-1));
    vvi dist(n,vi(n,-1));
    dist[nowi][nowj] = 0;
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        if(i==gi && j==gj) break;
        rep(v,4){
            int ni = i+di[v], nj = j+dj[v];
            if(ni<0 || nj<0 || ni>=n || nj>=n) continue;
            if(c[ni][nj]=='#') continue;
            if(dist[ni][nj]<dist[i][j] + (int)(c[i][j]-'0')) continue;
            dist[ni][nj] = dist[i][j] + (int)(c[i][j]-'0');
            prev[ni][nj] = i*n+j;
            q.push({ni,nj});
        }
    }
    res += dist[gi][gj];
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    input();

    // 交差点をチェック
    vector<P> crossPoint;
    crossPoint.push_back({si,sj});
    rep(i,n)rep(j,n){
        if(c[i][j]=='#') continue;
        int cnt = 0;
        rep(v,4){
            int ni = i+di[v], nj = j+dj[v];
            if(ni<0 || nj<0 || ni>=n || nj>=n) continue;
            if(c[ni][nj]=='#') continue;
            cnt++;
        }
        if(cnt>=3 && !(si==i&&sj==j)) crossPoint.push_back({i,j});
        else if((i==0 || i==n-1) && (j==0 || j==n-1) && cnt==2 && !(si==i&&sj==j)) crossPoint.push_back({i,j});
    }
    crossPoint.push_back({si,sj});

    string fAns;
    int len = crossPoint.size();
    rep(i,len-1)for(int j=i+2; j<len-1; j++){
         int pCst = costCalc(crossPoint, i, i+1) + costCalc(crossPoint, j,j+1);
         int nCst = costCalc(crossPoint, i, j) + costCalc(crossPoint, i+1,j+1);
         if(nCst<pCst){
             rep(_,(j-i)/2) swap(crossPoint[i+1+_], crossPoint[j-_]); 
         }
     }

    std::random_device rnd;     // 非決定的な乱数生成器を生成
    std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
    std::uniform_int_distribution<> rand(0, len-1);

    int cnt = 0;
    while(cnt<50000){
        cnt++;
        int i = rand(mt); int j = rand(mt);
        if(abs(i-j)<3) continue;
        int pCst = costCalc(crossPoint, i, i+1) + costCalc(crossPoint, j,j+1);
        int nCst = costCalc(crossPoint, i, j) + costCalc(crossPoint, i+1,j+1);
        if(nCst<pCst){
            rep(_,(j-i)/2) swap(crossPoint[i+1+_], crossPoint[j-_]); 
        }
    }

    int COST = 0;
    rep(_,crossPoint.size()-1){
        auto [nowi, nowj] = crossPoint[_];
        auto [gi,gj] = crossPoint[_+1];
        queue<P> q;
        q.push({nowi,nowj});
        vvi prev(n,vi(n,-1));
        vvi dist(n,vi(n,INF));
        dist[nowi][nowj] = 0;
        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            if(i==gi && j==gj) break;
            rep(v,4){
                int ni = i+di[v], nj = j+dj[v];
                if(ni<0 || nj<0 || ni>=n || nj>=n) continue;
                if(c[ni][nj]=='#') continue;
                if(dist[ni][nj]<dist[i][j] + (int)(c[i][j]-'0')) continue;
                dist[ni][nj] = dist[i][j] + (int)(c[i][j]-'0');
                prev[ni][nj] = i*n+j;
                q.push({ni,nj});
            }
        }
        COST += dist[gi][gj];
        string path = "";
        int ri = gi, rj = gj;
        while(1){
            if(ri==nowi && rj==nowj) break;
            int pi = prev[ri][rj]/n;
            int pj = prev[ri][rj]%n;
            rep(v,4) if(di[v]==ri-pi && dj[v]==rj-pj) path+=dir[v];
            ri = pi; rj = pj;
        }
        reverse(all(path));
        fAns += path;
    }
    cerr << COST << endl;
    cout << fAns << endl;
    

}