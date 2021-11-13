/**
*    author:  shu8Cream
*    created: 09.11.2021 12:40:02
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=(n-1); i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
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
 
int n,m,k,r;
double skills[1010][20];
vvi to;
vvi rto;
// 0: free, 1<=: working
int doingMem[20];
int waitMem[20];
// 0: non, 1: doing, -1: done
int finishTask[1010];
vector<pair<int,vector<double>>> predictMemSkill(20);
 
void initInput(){
    cin >> n >> m >> k >> r;
    rep(i,n)rep(j,k) cin >> skills[i][j];
    to.resize(n);
    rto.resize(n);
    rep(i,r){
        int u,v; cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
        rto[v].push_back(u);
    }
}
 
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
 
    initInput();
 
    // ランダムにタスクを入れ替える
    vi sortedTaskIndex(n);
    rep(i,n) sortedTaskIndex[i] = i;
 
    rep(i,m) predictMemSkill[i].first = 1;
    rep(i,m)rep(j,k) predictMemSkill[i].second.push_back(5);
 
    int N,tmp;
    map<int,int> Wariate;
    int days = 0;
    int taskCnt = 0;
    while(1){
        days++;
        vector<P> ret;
        for(int j : sortedTaskIndex){
            if(sz(rto[j])==0 && finishTask[j]!=0) continue;
            bool can = false;
            if(finishTask[j]==0){
                can = true;
                for(auto p : rto[j]){
                    if(finishTask[p]!=-1) can = false;  
                }
            }
            if(!can) continue;
 
            int nearMem = -1;
            double pcnt = 1e9;
            rep(i,m){
                if(doingMem[i]!=0) continue;
                double cnt = 0;
                rep(l,k){
                    if(predictMemSkill[i].first!=0){
                        double cc = predictMemSkill[i].second[l]/predictMemSkill[i].first - skills[j][l];
                        if(cc<0.0) cnt += 51.2;
                        else cnt += cc;
                    }else{
                        // cnt += skills[i][l];
                        cnt += 20;
                    }
                }
                if(pcnt>cnt){
                    nearMem = i;
                    pcnt = cnt;
                }
            }
            if(nearMem==-1) continue;
            ret.push_back({nearMem+1,j+1});
            doingMem[nearMem] = 1;
            finishTask[j] = 1;
            Wariate[nearMem] = j;            
        }
        
        cout << sz(ret) << " ";
        rep(i,sz(ret)) cout << ret[i].first << " " << ret[i].second << " ";
        cout << endl;
 
        cin >> N;
        if(N==-1) return 0;
        taskCnt = 0;
        rep(i,1000) if(finishTask[i]==-1) taskCnt++;
        rep(i,N){
            cin >> tmp; tmp--;

            double sum = 0;
            rep(I,k) sum += skills[tmp][I];

            double prm = sqrt(sum/(34*k));
 
            //ここでメンバーのスキルを予測する
            if(doingMem[tmp]<=12 || days<=40){
                predictMemSkill[tmp].first++;
                if(doingMem[tmp]<=12) rep(j,k) predictMemSkill[tmp].second[j] += skills[Wariate[tmp]][j]*2.85;
                else rep(j,k) predictMemSkill[tmp].second[j] += skills[Wariate[tmp]][j]*2.85*prm;
            }else if(days<=200){
                predictMemSkill[tmp].first++;
                rep(j,k) predictMemSkill[tmp].second[j] += skills[Wariate[tmp]][j]*1.5*prm;
            }else{
                predictMemSkill[tmp].first++;
                rep(j,k) predictMemSkill[tmp].second[j] += skills[Wariate[tmp]][j]/1.26;
            }

            // 待ち続ける人もリセット
            rep(j,m){
                if(doingMem[j]!=0) waitMem[j] = 0;
                else waitMem[j]++;
            }

            rep(j,m){
                if(waitMem[j]>120){
                    predictMemSkill[j].first = 1;
                    rep(J,k) predictMemSkill[j].second[J] = 15;
                }
            }
 
 
            doingMem[tmp] = 0;
            if(Wariate.count(tmp)) finishTask[Wariate[tmp]] = -1;
            Wariate.erase(tmp);
        }
        for(auto [mem,task] : Wariate) doingMem[mem]++;
    }
}