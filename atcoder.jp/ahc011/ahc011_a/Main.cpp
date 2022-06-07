/**
*    author:  shu8Cream
*    created: 28.05.2022 12:08:02
**/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define overload3(a,b,c,d,...) d
#define rep1(i,n) for (int i=0; i<(n); i++)
#define rep2(i,a,n) for (int i=(a); i<(n); i++)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define rrep1(i,n) for (int i=(n-1); i>=0; i--)
#define rrep2(i,a,n) for (int i=(n-1); i>=(a); i--)
#define rrep(...) overload3(__VA_ARGS__, rrep2, rrep1)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define pcnt __builtin_popcountll
using ll = long long;
using P = pair<int,int>;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vi = vc<ll>;
using vvi = vv<ll>;
const ll INF = 8e18;
template<typename T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const T&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.first>>v.second;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.first<<","<<v.second;}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}

template <class T> string to_string(T s);
template <class S, class T> string to_string(pair<S, T> p);
string to_string(char c) { return string(1, c); }
string to_string(string s) { return s; }
string to_string(const char s[]) { return string(s); }

template <class T>
string to_string(T v) {
    if (v.empty()) return "{}";
    string ret = "{";
    for (auto x : v) ret += to_string(x) + ",";
    ret.back() = '}';
    return ret;
}
template <class S, class T>
string to_string(pair<S, T> p) {
    return "{" + to_string(p.first) + ":" + to_string(p.second) + "}";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << to_string(H) << " ";
    debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

int n, t;
vv<int> field;
int si,sj;
string ans = "";

const vi di = {1,0,-1,0};
const vi dj = {0,1,0,-1};
const string direction = "DRUL";
const map<char,int> redirection = {{'D',0}, {'R',1}, {'U',2}, {'L',3}};

struct Xorshift{
    unsigned int x,y,z,w;
    Xorshift(unsigned int x=123456789, unsigned int y=362436069, unsigned int z=521288629, unsigned int w=88675123) : x(x),y(y),z(z),w(w) {
        assert(x!=0 || y!=0 || z!=0 || w!=0);
    }
    unsigned int operator()(){
        unsigned int t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
    }
};

Xorshift x128;

// 0以上1未満の小数をとる乱数
static double rand01(){
    return (x128() + 0.5) * (1.0 / UINT_MAX);
}


void input(){
    cin >> n >> t;
    field = vv<int>(n,vc<int>(n));
    rep(i,n)rep(j,n){
        char c; cin >> c;
        int tile = 0;
        if('a'<=c && c<='f') tile = c-'a'+10;
        else tile = c-'0';
        field[i][j] = tile;
        if(tile==0){
            si = i;
            sj = j;
        }
    }
}

// 最大木の大きさを計算
P calc(){
    int res = 1;
    // 別指標のスコア
    int rev_score = 0;
    vv<int> seen(n,vc<int>(n));

    auto out_of_grid = [&](int x, int y)->bool{
        return ((x<0 || x>=n || y<0 || y>=n) ? true : false);
    };

    auto dfs = [&](auto dfs, P s, P p=P(-1,-1))->int{
        // pre-order
        int ret = 1;
        auto[i,j] = s;
        if(seen[i][j]) return -100;
        seen[i][j] = 1; 
        rep(v,4){
            int ni = i+di[v], nj = j+dj[v];
            if(out_of_grid(ni,nj)) continue;
            if(P(ni,nj)==p) continue;
            if((v==0 && field[i][j]>=8 && field[ni][nj]%4/2==1)
            || (v==1 && field[i][j]/4%2==1 && field[ni][nj]%2==1)
            || (v==2 && field[ni][nj]>=8 && field[i][j]%4/2==1)
            || (v==3 && field[ni][nj]/4%2==1 && field[i][j]%2==1)){
                ret += dfs(dfs,P(ni,nj),P(i,j));
            }
            // in-order
        }
        // post-order
        return ret;
    };

    vc<int> connect_parts;
    // DRUL
    rep(i,n)rep(j,n){
        if(seen[i][j] || field[i][j]==0) continue;
        int tmp = dfs(dfs,P(i,j));
        connect_parts.push_back(tmp);
        chmax(res,tmp);
        int cnt = 0;
        rep(v,4){
            int ni = i+di[v], nj = j+dj[v];
            if(!out_of_grid(ni,nj)){
                if((v==0 && ((field[i][j]>=8) == (field[ni][nj]%4/2==1)))
                || (v==1 && ((field[i][j]/4%2==1) == (field[ni][nj]%2==1)))
                || (v==2 && ((field[ni][nj]>=8) == (field[i][j]%4/2==1)))
                || (v==3 && ((field[ni][nj]/4%2==1) == (field[i][j]%2==1)))){
                    cnt++;
                }else cnt--;
            }else{
                if((v==0 && field[i][j]>=8)
                || (v==1 && field[i][j]/4%2==1)
                || (v==2 && field[i][j]%4/2==1)
                || (v==3 && field[i][j]%2==1)){
                    cnt--;
                }else cnt++;
            }
        }
        // if(cnt<=0) rev_score+=800*(cnt-2);
        
        if(field[i][j]==1 || field[i][j]==2 || field[i][j]==4 || field[i][j]==8){
            rev_score+=1300*(cnt-1);
        }else{
            rev_score+=800*(cnt-1);
        }
    }
    for(auto p : connect_parts) rev_score += p;
    return {res,rev_score};
}

P get_score(int opcnt){
    if(opcnt>t) return {0,0};
    int res = 500000;
    auto[s,other] = calc();
    // 実際のスコア
    int true_score = 0;
    if(n*n-1==s){
        double tmp = 2.0-double(opcnt/t);
        res = round(tmp*res);
        debug(tmp,res);
    }else{
        double tmp = double(s)/(n*n-1);
        res = round(tmp*res);
        true_score = res;
        res += other;
    }
    return {true_score,res};
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    #ifdef _DEBUG
    FILE *fp;
    fp = fopen("./out/score9.txt", "a");
    #endif

    input();

    int total_ope = 0;
    auto startClock = system_clock::now();
    int score = get_score(total_ope).second;
    int trueScore = get_score(total_ope).first;
    int bestScore = INT_MIN;
    int bestPoint = -1;
    vc<string> bestSnapshot;

    const static double START_TEMP = 1500; // 開始時の温度
    const static double END_TEMP   =  100; // 終了時の温度
    const static double END_TIME   =  2.90; // 終了時間（秒）

    double time = 0.0;   // 経過時間（秒）
    int turn;
    do{
        const double progressRatio = time / END_TIME;   // 進捗。開始時が0.0、終了時が1.0
        const double temp = START_TEMP + (END_TEMP - START_TEMP) * progressRatio;

        // 空白の位置を移動してみる
        int deltaScore = 0; // スコアの差分 = 変更後のスコア - 変更前のスコア
        int deltaTrueScore = 0;
        vc<int> bkup_i; bkup_i.push_back(si);
        vc<int> bkup_j; bkup_j.push_back(sj);
        deltaScore -= get_score(total_ope).second;
        deltaTrueScore -= get_score(total_ope).first;

        // turn = x128()%(int(double(n/6)*30))+10;
        // turn = n+5;
        turn = 11;
        int pi = -1, pj = -1;
        rep(loop,turn){
            int d = x128() % 4;
            while(si+di[d]<0 || si+di[d]>=n || sj+dj[d]<0 || sj+dj[d]>=n || (pi==si+di[d] && pj==sj+dj[d])){
                d = x128() % 4;
            }
            int ni = si+di[d], nj = sj+dj[d];
            pi = si; pj = sj;
            bkup_i.push_back(ni);
            bkup_j.push_back(nj);
            swap(field[si][sj],field[ni][nj]);
            ans += direction[d];
            total_ope++;
            swap(si,ni); swap(sj,nj);
        }
        deltaScore += get_score(total_ope).second;
        deltaTrueScore += get_score(total_ope).first;
        const double probability = exp(deltaScore / temp); // 焼きなまし法の遷移確率

        if (probability > rand01()){
            // 変更を受け入れる。スコアを更新
            score += deltaScore;
            trueScore += deltaTrueScore;
            if (score > bestScore){
                bestScore = trueScore;
                // debug("tmp:",bestScore);
                // cerr << "tmp: " << bestScore << endl;
                debug("===============");
                debug(ans);
                debug("===============");
                bestSnapshot.push_back(ans);
                bestPoint = sz(bestSnapshot)-1;
            }
        }else{
            // 変更を受け入れないので、元に戻す
            total_ope-=turn;
            ans = ans.substr(0,sz(ans)-turn);
            rrep(bi,sz(bkup_i)-1){
                int ni = bkup_i[bi], nj = bkup_j[bi];
                swap(field[si][sj],field[ni][nj]);
                swap(si,ni); swap(sj,nj);
            }
        }

        time = (duration_cast<microseconds>(system_clock::now() - startClock).count() * 1e-6);
    } while (time < END_TIME);
    // 焼きなまし法（ここまで）
    #ifdef _DEBUG
    fprintf(fp, "%d\n", bestScore);
    #endif
    if(sz(bestSnapshot)) ans = bestSnapshot[bestPoint];
    cout << ans << endl;

    #ifdef _DEBUG
    fclose(fp);
    #endif
}