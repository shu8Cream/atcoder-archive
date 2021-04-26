/**
*    author:  shu8Cream
*    created: 26.04.2021 09:06:13
**/

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using namespace std::chrono;
inline double get_time_sec(void){
    return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

int si,sj;
vvi t(50,vi(50));
vvi p(50,vi(50));

string finans = "";
int finscore = 0;

const vi di = {1,0,-1,0};
const vi dj = {0,1,0,-1};

void input(){
    cin >> si >> sj;
    rep(i,50)rep(j,50) cin >> t[i][j];
    rep(i,50)rep(j,50) cin >> p[i][j];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    input();

    set<int> allrem;
    int loop = 16;
    while(loop--){
        double start = get_time_sec();
        int score = 0;
        string ans = "";
        vector<P> remcell;

        while(get_time_sec() - start<0.124){

            int tscore = 0;
            string tans = "";
            set<int> rem;
            queue<P> pq;
            pq.push({si,sj});
            int i=0,j=0;
            while(!pq.empty()){
                int pi=i,pj=j;
                tie(i,j) = pq.front(); pq.pop();
                remcell.push_back({i,j});
                rem.insert(t[i][j]);
                tscore += p[i][j];
                queue<P> emp;
                swap(pq,emp);

                if(!(i == si && j == sj)){
                    if(i-pi==1) tans+="D";
                    else if(i-pi==-1) tans+="U";
                    else if(j-pj==1) tans+="R";
                    else if(j-pj==-1) tans+="L";
                }

                // cout << ans << endl;

                vi rand = {0,1,2,3};

                std::random_device seed_gen;
                std::mt19937 engine(seed_gen());
                shuffle(all(rand),engine);
                for(auto k : rand){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni<0 || ni>=50 || nj<0 || nj>=50) continue;
                    if(t[i][j]==t[ni][nj]) continue;
                    if(rem.count(t[ni][nj])) continue;
                    if(allrem.count(t[ni][nj])) continue;

                    int ngcnt = 0;
                    rep(kk,4){
                        int nni = ni + di[kk];
                        int nnj = nj + dj[kk];
                        if(nni<0 || nni>=50 || nnj<0 || nnj>=50) {ngcnt++; continue;}
                        if(t[nni][nnj]==t[ni][nj]) {ngcnt++; continue;}
                        if(rem.count(t[nni][nnj])) {ngcnt++; continue;}
                        if(allrem.count(t[nni][nnj])) {ngcnt++; continue;}
                    }
                    if(ngcnt==4) continue;

                    pq.push({ni,nj}); 
                }
            }

            if(tscore>score){
                score = tscore;
                ans = tans;
            }

        }

        int anslen = (ans.size()+1)/2;
        ans = ans.substr(0,anslen);
        
        finans += ans;

        allrem.insert(t[si][sj]);
        rep(k,anslen){
            if(ans[k]=='U') si--;
            if(ans[k]=='D') si++;
            if(ans[k]=='L') sj--;
            if(ans[k]=='R') sj++;
            allrem.insert(t[si][sj]);
        }
    }
    cout << finans << endl;
}