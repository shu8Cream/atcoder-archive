/**
*    author:  shu8Cream
*    created: 21.02.2022 21:02:12
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
const int INF = 1e9;

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

const vi di = {0,1,0,-1};
const vi dj = {-1,0,1,0};
const string direction = "LDRU";
const string block_key = "ldru";

const int h = 30;
const int w = 30;
const int turn = 300;

int rndint(int l, int r){
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand(l, r);
    return rand(mt);
}

int n,m;
// pet: 1~5, human: 6, wall: -1, none: 0
vvi field(h,vi(w));
map<int,P> pet_pos;
map<int,P> human_pos;
map<int,set<P>> my_territory;
vi pet_knd;
int dog_cnt = 0;

const vector<string> room_struct = {
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "##############--##############",
                        "..............oo..............",
                        "..............oo.............."
                        };

const vector<string> room_struct2 = {
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        "#########--########--#########",
                        ".........oo........oo.........",
                        ".........oo........oo........."
                        };



// 更新作業は遅延して行う必要がある
// 0: 人
map<int,P> human_update;

void input(){
    cin >> n;
    // ペットの配置1~5
    int pi,pj,pt;
    pet_knd.resize(n);
    rep(i,n){
        cin >> pi >> pj >> pt;
        pi--; pj--;
        // field[pi][pj] = pt;
        pet_pos[i] = {pi,pj};
        pet_knd[i] = pt;
        if(pt==4) dog_cnt++;
    }

    cin >> m;
    // 人の配置6
    int hi,hj;
    rep(i,m){
        cin >> hi >> hj;
        hi--; hj--;
        // field[hi][hj] = 6;
        human_pos[i] = {hi,hj};
    }
}

// フィールドの外ならTrue
bool out_of_grid(int x, int y){
    if(x<0 || x>=h || y<0 || y>=w) return true;
    return field[x][y]==-1;
}

// ペットと位置が被るとTrue
// ペットの隣接マスもTrue
bool pet_check(int x, int y){
    rep(idx,n)if(pet_pos[idx]==P(x,y)) return true;
    rep(idx,n){
        auto[i,j] = pet_pos[idx];
        rep(v,4){
            int ni = i+di[v];
            int nj = j+dj[v];
            if(out_of_grid(ni,nj)) continue;
            if(P(ni,nj)==P(x,y)) return true;
        }
    }
    return false;
}

// 人と位置が被るとTrue
bool human_check(int x, int y, int my_idx){
    rep(idx,m)if(idx!=my_idx && human_pos[idx]==P(x,y)) return true;
    rep(idx,m)if(idx!=my_idx && human_update.count(idx) && human_update[idx]==P(x,y)) return true;
    return false;
}

bool myterty_check(int x, int y, int my_idx){
    rep(idx,m)for(auto p : my_territory[idx]){
        if(p==P(x,y)) return true;
    }
    return false;
}

// 人の周りの壁の数をカウント
// 自分のテリトリーの壁にカウント
int wall_counter(int x, int y, int my_idx){
    int cnt = 0;
    rep(v,4){
        int ni = x+di[v];
        int nj = y+dj[v];
        if(ni<0 || ni>=h || nj<0 || nj>=w){
            cnt++;
            continue;
        }
        if(field[ni][nj]==-1) cnt++;
        if(myterty_check(ni,nj,my_idx)) cnt++;
    }
    return cnt;
}

double bfs(P start_pos){
    ll cnt = 0;
    vvi seen(h,vi(w));
    queue<P> q; q.push(start_pos);
    while(!q.empty()){
        auto[i,j] = q.front(); q.pop();
        seen[i][j] = 1;
        cnt++;
        rep(v,4){
            int ni = i+di[v], nj = j+dj[v];
            if(out_of_grid(ni,nj)) continue;
            if(seen[ni][nj]) continue;
            seen[ni][nj] = 1;
            q.push({ni,nj});
        }
    }
    double sc = (double)cnt/900.0;
    rep(idx,n){
        auto[i,j] = pet_pos[idx];
        if(seen[i][j]) sc/=2.0;
    }
    return sc;
}

ll score_calc(){
    double score = 0;
    rep(idx,m) score+=bfs(human_pos[idx]);
    score/=m;
    ll ret = round(score*100000000);
    return ret;
}

void pet_move(){
    string move;
    rep(i,n){
        cin >> move;
        rep(j,sz(move))rep(v,4)if(direction[v]==move[j]){
            auto[pi,pj] = pet_pos[i];
            int ni = pi+di[v], nj = pj+dj[v];
            // field[ni][nj] = field[pi][pj];
            // field[pi][pj] = 0;
            pet_pos[i] = {ni,nj};
        }
    }
}

vvi calc_dist(P start){
    auto[i,j] = start;
    vvi dist(h,vi(w,INF)); dist[i][j] = 0;
    queue<P> q; q.push(start);

    while (!q.empty()) {
        auto[pi,pj] = q.front(); q.pop();
        rep(v,4){
            int ni = pi+di[v], nj = pj+dj[v];
            if(out_of_grid(ni,nj)) continue;
            if(dist[ni][nj]!=INF) continue;
            dist[ni][nj] = dist[pi][pj] + 1;
            q.push(P(ni,nj));
        }
    }
    return dist;
}

char move(P start, P goal,int id){
    auto[i,j] = start;
    vvi dist(h,vi(w,-1));
    map<P,P> prev;
    queue<P> q;
    dist[i][j] = 0;
    q.push(start);

    while (!q.empty()) {
        auto[pi,pj] = q.front(); q.pop();
        if(P(pi,pj)==goal) break;
        rep(v,4){
            int ni = pi+di[v], nj = pj+dj[v];
            if(out_of_grid(ni,nj)) continue;
            if(dist[ni][nj]!=-1) continue;
            dist[ni][nj] = dist[pi][pj] + 1;
            prev[P(ni,nj)] = P(pi,pj);
            q.push({ni,nj});
        }
    }
    // 最短経路の経路復元、curにゴールを入れる
    P cur = goal;
    vector<P> res;
    while(cur!=start){
        res.push_back(cur);
        cur = prev[cur];
    }
    if(!res.empty()){
        auto[ti,tj] = res[sz(res)-1];
        rep(v,4)if(di[v]==ti-i && dj[v]==tj-j && field[ti][tj]!=-1){
            human_update[id] = {ti,tj};
            // human_pos[id] = {ti,tj};
            return direction[v];
        }
    }
    return '.';
}

void m1() {

    set<P> start_pos;
    for(int i=2; i<h; i+=4){
        start_pos.insert({i,0});
        start_pos.insert({i,29});
    }

    // ループ部分
    vector<P> prev(m,{-1,-1});
    vector<P> aim(m,{-1,-1});
    vi arrived(m);
    set<P> choose;
    rep(_,turn){
        string ret = string(m,'.');
        // if(score_calc()<=1000000){

        //     cout << ret << endl;
        //     // 動作受け取り
        //     pet_move();
        //     cout << "# " << score_calc() << endl;
        //     continue;
        // }
        debug("# start_pos", start_pos);
        rep(id,m){
            auto[i,j] = human_pos[id];
            // スタートポジションへ移動
            if(arrived[id]==0){
                if(aim[id]==P(-1,-1)){
                    vvi st_pos_dist = calc_dist(human_pos[id]);
                    int diff = INF;
                    for(auto[si,sj]:start_pos){
                        if(choose.count(P(si,sj))) continue;
                        int ndiff = st_pos_dist[si][sj];
                        if(ndiff<diff){
                            aim[id] = {si,sj};
                            diff = ndiff;
                        }
                    }
                    if(aim[id]!=P(-1,-1)) choose.insert(aim[id]);
                }
                if(aim[id]!=P(-1,-1)){
                    // choose.insert(aim[id]);
                    cout << "# " << aim[id].first << " " << aim[id].second << endl;
                    ret[id] = move(human_pos[id],aim[id],id);
                    cout << "# " << "スタートへ移動" << id+1 << endl;
                }else{
                    bool catch_flg = false;
                    rep(pid,n){
                        auto[pi,pj] = pet_pos[pid];
                        if(i!=pi) continue;
                        if(j==14 && pj<j-2){
                            if(i!=29 && i-1>=0 && field[i-1][j-1]!=-1) continue;
                            if(i+1<h && field[i+1][j-1]!=-1) continue;
                            bool f = false;
                            for(int k=j; k>=pj; k--)if(field[i][k]==-1) f = true;
                            if(f) continue;
                            if(field[i][j-1]==-1) continue;
                            if(human_check(i,j-1,id)) continue;
                            if(pet_check(i,j-1)) continue;
                            ret[id] = block_key[0];
                            field[i][j-1] = -1;
                            catch_flg = true;
                            break;
                        }else if(j==15 && j+2<pj){
                            if(i!=29 && i-1>=0 && field[i-1][j+1]!=-1) continue;
                            if(i+1<h && field[i+1][j+1]!=-1) continue;
                            bool f = false;
                            for(int k=j; k<=pj; k++)if(field[i][k]==-1) f = true;
                            if(f) continue;
                            if(field[i][j+1]==-1) continue;
                            if(human_check(i,j+1,id)) continue;
                            if(pet_check(i,j+1)) continue;
                            ret[id] = block_key[2];
                            field[i][j+1] = -1;
                            catch_flg = true;
                            break;
                        }
                    }

                    if(!catch_flg){
                        bool p_exist = false, decide = false;;
                        rep(pid,n){
                            auto[pi,pj] = pet_pos[pid];
                            if(i==pi && (j==14 || j==15) && pj<=13){
                                bool f = false;
                                for(int k=j; k>=pj; k--)if(field[i][k]==-1) f = true;
                                if(!f){
                                    if(pj==12 || pj==13){
                                        decide = true;
                                        break;
                                    }
                                    if(j==15){
                                        ret[id] = direction[0];
                                        human_update[id] = {i,j-1};
                                        decide = true;
                                        break;
                                    }
                                }
                            }
                            if(i==pi && (j==14 || j==15) && pj>=16){
                                bool f = false;
                                for(int k=j; k<=pj; k++)if(field[i][k]==-1) f = true;
                                if(!f){
                                    if(pj==16 || pj==17){
                                        decide = true;
                                        break;
                                    }
                                    if(j==14){
                                        ret[id] = direction[2];
                                        human_update[id] = {i,j+1};
                                        decide = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if(!decide){ 
                        if(j==14 && i==29){
                            ret[id] = direction[2];
                            human_update[id] = {i,j+1};
                        }else if(j==14){
                            ret[id] = direction[1];
                            human_update[id] = {i+1,j};
                        }else if(j==15 && i==0){
                            ret[id] = direction[0];
                            human_update[id] = {i,j-1};
                        }else{
                            ret[id] = direction[3];
                            human_update[id] = {i-1,j};
                        }
                        }
                    }
                }
            }else{
                bool catch_flg = false;
                rep(pid,n){
                    auto[pi,pj] = pet_pos[pid];
                    if(i!=pi) continue;
                    if(j<15 && aim[id].second==0 && pj<j-2){
                        bool f = false;
                        for(int k=j; k>=pj; k--)if(field[i][k]==-1) f = true;
                        if(f) continue;
                        if(field[i][j-1]==-1) continue;
                        if(human_check(i,j-1,id)) continue;
                        if(pet_check(i,j-1)) continue;
                        ret[id] = block_key[0];
                        field[i][j-1] = -1;
                        catch_flg = true;
                        break;
                    }else if(14<j && aim[id].second==29 && j+2<pj){
                        bool f = false;
                        for(int k=j; k<=pj; k++)if(field[i][k]==-1) f = true;
                        if(f) continue;
                        if(field[i][j+1]==-1) continue;
                        if(human_check(i,j+1,id)) continue;
                        if(pet_check(i,j+1)) continue;
                        ret[id] = block_key[2];
                        field[i][j+1] = -1;
                        catch_flg = true;
                        break;
                    }
                }

                if(!catch_flg){
                if(field[i-1][j]==-1 && field[i+1][j]==-1){
                    auto[ai,aj] = aim[id];
                    if(aj==0 && room_struct[i][j]=='.'){
                        ret[id] = direction[2];
                        human_update[id] = {i,j+1};
                    }else if(aj==29 && room_struct[i][j]=='.'){
                        ret[id] = direction[0];
                        human_update[id] = {i,j-1};
                    }
                }else{
                    if(room_struct[i][j]=='.' && field[i+1][j]!=-1 && !human_check(i+1,j,id) && !pet_check(i+1,j)){
                        ret[id] = block_key[1];
                        field[i+1][j] = -1;
                    }else if(room_struct[i][j]=='.' && field[i-1][j]!=-1 && !human_check(i-1,j,id) && !pet_check(i-1,j)){
                        ret[id] = block_key[3];
                        field[i-1][j] = -1;
                    }
                }
                }
            }
        }

        for(auto[idx,update]:human_update) human_pos[idx] = update;
        map<int,P> emp; swap(emp,human_update);

        // rep(id,m){
        //     if(aim[id]!=P(-1,-1) && !first_start_pos.count(aim[id]) && field[aim[id].first][aim[id].second]==-1){
        //         aim[id] = {-1,-1};
        //         prev[id] = {-1,-1};
        //         start_pos.erase(aim[id]);
        //     }
        // }

        rep(id,m)if(human_pos[id]==aim[id]){
            start_pos.erase(aim[id]);
            choose.erase(aim[id]);
            arrived[id] = 1;
        }
        rep(id,m){
            auto[ui,uj] = human_pos[id];
            if(arrived[id] && (room_struct[ui][uj]=='o' || room_struct[ui][uj]=='-')){
                aim[id] = {-1,-1};
                arrived[id] = 0;
                prev[id] = {-1,-1};
            }
        }

        cout << ret << endl;
        // 動作受け取り
        pet_move();
        cout << "# " << score_calc() << endl;
    }
}

void m2(){
    set<P> start_pos;
    for(int i=2; i<h; i+=4){
        start_pos.insert({i,0});
        start_pos.insert({i,11});
        start_pos.insert({i,29});
    }

    // ループ部分
    vector<P> prev(m,{-1,-1});
    vector<P> aim(m,{-1,-1});
    vi arrived(m);
    set<P> choose;
    rep(_,turn){
        string ret = string(m,'.');
        if(_>270 && score_calc()<=2000000){
            rep(id,m){
                auto[i,j] = human_pos[id];
                if(i==14){
                    if(field[i+1][j]==-1) continue;
                    if(human_check(i+1,j,id)) continue;
                    if(pet_check(i+1,j)) continue;
                    ret[id] = block_key[1];
                    field[i+1][j] = -1;
                }
                if(i==16){
                    if(field[i-1][j]==-1) continue;
                    if(human_check(i-1,j,id)) continue;
                    if(pet_check(i-1,j)) continue;
                    ret[id] = block_key[3];
                    field[i-1][j] = -1;
                }
                if(ret[id]=='.'){
                    if((j==9 || j==19) && (i==29 || field[i+1][j]==-1)){
                        ret[id] = direction[2];
                        human_update[id] = {i,j+1};
                    }else if((j==9 || j==19)){
                        ret[id] = direction[1];
                        human_update[id] = {i+1,j};
                    }else if((j==10 || j==20) && (i==0 || field[i-1][j]==-1)){
                        ret[id] = direction[0];
                        human_update[id] = {i,j-1};
                    }else{
                        ret[id] = direction[3];
                        human_update[id] = {i-1,j};
                    }
                }
            }
            for(auto[idx,update]:human_update) human_pos[idx] = update;
            map<int,P> emp; swap(emp,human_update);
            cout << ret << endl;
            // 動作受け取り
            pet_move();
            cout << "# " << score_calc() << endl;
            continue;
        }
        debug("# start_pos", start_pos);
        rep(id,m){
            auto[i,j] = human_pos[id];
            // スタートポジションへ移動
            if(arrived[id]==0){
                // スタートポジションを検索
                if(aim[id]==P(-1,-1)){
                    vvi st_pos_dist = calc_dist(human_pos[id]);
                    int diff = INF;
                    for(auto[si,sj]:start_pos){
                        if(choose.count(P(si,sj))) continue;
                        int ndiff = st_pos_dist[si][sj];
                        if(ndiff<diff){
                            aim[id] = {si,sj};
                            diff = ndiff;
                        }
                    }
                    // if(diff==INF) start_pos.clear();
                    if(aim[id]!=P(-1,-1)) choose.insert(aim[id]);
                }

                // 目標がある場合に、目標へ移動する
                if(aim[id]!=P(-1,-1)){
                    // choose.insert(aim[id]);
                    cout << "# " << aim[id].first << " " << aim[id].second << endl;
                    ret[id] = move(human_pos[id],aim[id],id);
                    cout << "# " << "スタートへ移動" << id+1 << endl;
                }else{
                // ペットを捕まえる
                    bool catch_flg = false;
                    rep(pid,n){
                        auto[pi,pj] = pet_pos[pid];
                        if(i!=pi) continue;
                        if(j==9 && pj<j-2){
                            if(i!=29 && i-1>=0 && field[i-1][j-1]!=-1) continue;
                            if(i+1<h && field[i+1][j-1]!=-1) continue;
                            bool f = false;
                            for(int k=j; k>=pj; k--)if(field[i][k]==-1) f = true;
                            if(f) continue;
                            if(field[i][j-1]==-1) continue;
                            if(human_check(i,j-1,id)) continue;
                            if(pet_check(i,j-1)) continue;
                            ret[id] = block_key[0];
                            field[i][j-1] = -1;
                            catch_flg = true;
                            break;
                        }else if(j==20 && j+2<pj){
                            if(i!=29 && i-1>=0 && field[i-1][j+1]!=-1) continue;
                            if(i+1<h && field[i+1][j+1]!=-1) continue;
                            bool f = false;
                            for(int k=j; k<=pj; k++)if(field[i][k]==-1) f = true;
                            if(f) continue;
                            if(field[i][j+1]==-1) continue;
                            if(human_check(i,j+1,id)) continue;
                            if(pet_check(i,j+1)) continue;
                            ret[id] = block_key[2];
                            field[i][j+1] = -1;
                            catch_flg = true;
                            break;
                        }else if(j==19 && 12<=pj && pj<=16){
                            if(i!=29 && i-1>=0 && field[i-1][j-1]!=-1) continue;
                            if(i+1<h && field[i+1][j-1]!=-1) continue;
                            bool f = false;
                            for(int k=j; k>=pj; k--)if(field[i][k]==-1) f = true;
                            if(f) continue;
                            if(field[i][j-1]==-1) continue;
                            if(human_check(i,j-1,id)) continue;
                            if(pet_check(i,j-1)) continue;
                            ret[id] = block_key[0];
                            field[i][j-1] = -1;
                            catch_flg = true;
                            break;
                        }else if(j==10 && 13<=pj && pj<=17){
                            if(i!=29 && i-1>=0 && field[i-1][j+1]!=-1) continue;
                            if(i+1<h && field[i+1][j+1]!=-1) continue;
                            bool f = false;
                            for(int k=j; k<=pj; k++)if(field[i][k]==-1) f = true;
                            if(f) continue;
                            if(field[i][j+1]==-1) continue;
                            if(human_check(i,j+1,id)) continue;
                            if(pet_check(i,j+1)) continue;
                            ret[id] = block_key[2];
                            field[i][j+1] = -1;
                            catch_flg = true;
                            break;
                        }
                    }
                    // 回転
                    if(!catch_flg){
                        bool p_exist = false, decide = false;;
                        rep(pid,n){
                            auto[pi,pj] = pet_pos[pid];
                            if(i==pi && (j==9 || j==10) && pj<=7){
                                bool f = false;
                                for(int k=j; k>=pj; k--)if(field[i][k]==-1) f = true;
                                if(!f){
                                    if(pj==7 || pj==8){
                                        decide = true;
                                        break;
                                    }
                                    if(j==10){
                                        ret[id] = direction[0];
                                        human_update[id] = {i,j-1};
                                        decide = true;
                                        break;
                                    }
                                }
                            }
                            if(i==pi && (j==19 || j==20) && pj>=21){
                                bool f = false;
                                for(int k=j; k<=pj; k++)if(field[i][k]==-1) f = true;
                                if(!f){
                                    if(pj==21 || pj==22){
                                        decide = true;
                                        break;
                                    }
                                    if(j==19){
                                        ret[id] = direction[2];
                                        human_update[id] = {i,j+1};
                                        decide = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if(!decide){ 
                        if((j==9 || j==19) && (i==29 || field[i+1][j]==-1)){
                            ret[id] = direction[2];
                            human_update[id] = {i,j+1};
                        }else if((j==9 || j==19)){
                            ret[id] = direction[1];
                            human_update[id] = {i+1,j};
                        }else if((j==10 || j==20) && (i==0 || field[i-1][j]==-1)){
                            ret[id] = direction[0];
                            human_update[id] = {i,j-1};
                        }else{
                            ret[id] = direction[3];
                            human_update[id] = {i-1,j};
                        }
                        }
                    }
                }
            }else{
            // ペットを捕まえる
                bool catch_flg = false;
                rep(pid,n){
                    auto[pi,pj] = pet_pos[pid];
                    if(i!=pi) continue;
                    if(j<15 && aim[id].second==0 && pj<j-2){
                        bool f = false;
                        for(int k=j; k>=pj; k--)if(field[i][k]==-1) f = true;
                        if(f) continue;
                        if(field[i][j-1]==-1) continue;
                        if(human_check(i,j-1,id)) continue;
                        if(pet_check(i,j-1)) continue;
                        ret[id] = block_key[0];
                        field[i][j-1] = -1;
                        catch_flg = true;
                        break;
                    }else if(16<j && aim[id].second==29 && j+2<pj){
                        bool f = false;
                        for(int k=j; k<=pj; k++)if(field[i][k]==-1) f = true;
                        if(f) continue;
                        if(field[i][j+1]==-1) continue;
                        if(human_check(i,j+1,id)) continue;
                        if(pet_check(i,j+1)) continue;
                        ret[id] = block_key[2];
                        field[i][j+1] = -1;
                        catch_flg = true;
                        break;
                    }
                }

                if(!catch_flg){
                if(field[i-1][j]==-1 && field[i+1][j]==-1){
                    auto[ai,aj] = aim[id];
                    // もし周囲に犬がいたら一歩中に入る
                    bool dog_exist = false;
                    rep(pid,n){
                        for(int x=-1; x<2; x++)for(int y=-1; y<2; y++){
                            if(out_of_grid(i+x,j+y)) continue;
                            if(pet_pos[pid]==P(i+x,j+y) && pet_knd[pid]==4){
                                dog_exist = true;
                                break;
                            }
                        }
                        if(dog_exist) break;
                    }
                    if(dog_cnt<=4) dog_exist = false;
                    dog_cnt = false;
                    if(dog_exist) cout << "# " << id+1 << " 犬がいる!!" << endl;
                    if(dog_exist && aj==0 && j-1>=0 && field[i][j-1]!=-1){
                        ret[id] = direction[0];
                        human_update[id] = {i,j-1};
                    }else if(dog_exist && aj==29 && j+1<w && field[i][j+1]!=-1){
                        ret[id] = direction[2];
                        human_update[id] = {i,j+1};
                    }else if(aj==0 && room_struct2[i][j]=='.'){
                        ret[id] = direction[2];
                        human_update[id] = {i,j+1};
                    }else if(aj==29 && room_struct2[i][j]=='.'){
                        ret[id] = direction[0];
                        human_update[id] = {i,j-1};
                    }else if(aj==11 && room_struct2[i][j]=='.'){
                        ret[id] = direction[2];
                        human_update[id] = {i,j+1};
                    }
                }else{
                    auto[ai,aj] = aim[id];
                    // もし周囲に犬がいたら一歩中に入る
                    bool dog_exist = false;
                    rep(pid,n){
                        for(int x=-1; x<2; x++)for(int y=-1; y<2; y++){
                            if(out_of_grid(i+x,j+y)) continue;
                            if(pet_pos[pid]==P(i+x,j+y) && pet_knd[pid]==4){
                                dog_exist = true;
                                break;
                            }
                        }
                        if(dog_exist) break;
                    }
                    if(dog_cnt<4) dog_exist = false;
                    dog_cnt = false;
                    if(dog_exist) cout << "# " << id+1 << " 犬がいる!!" << endl;
                    if(dog_exist && aj==0 && j-1>=0  && field[i][j-1]!=-1){
                        ret[id] = direction[0];
                        human_update[id] = {i,j-1};
                    }else if(dog_exist && aj==29 && j+1<w && field[i][j+1]!=-1){
                        ret[id] = direction[2];
                        human_update[id] = {i,j+1};
                    }else 
                    if(room_struct2[i][j]=='.' && field[i+1][j]!=-1 && !human_check(i+1,j,id) && !pet_check(i+1,j)){
                        ret[id] = block_key[1];
                        field[i+1][j] = -1;
                    }else if(room_struct2[i][j]=='.' && field[i-1][j]!=-1 && !human_check(i-1,j,id) && !pet_check(i-1,j)){
                        ret[id] = block_key[3];
                        field[i-1][j] = -1;
                    }
                }
                }
            }
        }
        // if(_>=270){
        //     ll p_score = score_calc();
        //     if(p_score>1000000) continue;
        //     rep(id,m){
        //         auto[i,j] = human_pos[id];
        //         rep(v,4){
        //             int ni = i+di[v], nj = j+dj[v];
        //             if(field[ni][nj]==-1) continue;
        //             if(pet_check(ni,nj)) continue;
        //             if(human_check(ni,nj,id)) continue;
        //             field[ni][nj] = -1;
        //             ll n_score = score_calc();
        //             if(n_score>p_score){
        //                 ret[id] = block_key[v];
        //                 break;
        //             }else{
        //                 field[ni][nj] = 0;
        //             }

        //         }
        //     }
        //     // cout << ret << endl;
        //     // // 動作受け取り
        //     // pet_move();
        //     // cout << "# " << score_calc() << endl;
        //     // continue;
        // }

        for(auto[idx,update]:human_update) human_pos[idx] = update;
        map<int,P> emp; swap(emp,human_update);

        // rep(id,m){
        //     if(aim[id]!=P(-1,-1) && !first_start_pos.count(aim[id]) && field[aim[id].first][aim[id].second]==-1){
        //         aim[id] = {-1,-1};
        //         prev[id] = {-1,-1};
        //         start_pos.erase(aim[id]);
        //     }
        // }

        rep(id,m)if(human_pos[id]==aim[id]){
            start_pos.erase(aim[id]);
            choose.erase(aim[id]);
            arrived[id] = 1;
        }
        rep(id,m){
            auto[ui,uj] = human_pos[id];
            if(arrived[id] && (room_struct2[ui][uj]=='o' || room_struct2[ui][uj]=='-')){
                aim[id] = {-1,-1};
                arrived[id] = 0;
                prev[id] = {-1,-1};
            }
        }
        // int bias = 0;
        // rep(id,m){
        //     auto[ui,uj] = human_pos[id];
        //     if(uj==9 || uj==10) bias++;
        //     if(uj==19 || uj==20) bias--;
        // }
        // if(bias<=-2) start_pos.insert({15,10});
        // if(bias>=2) start_pos.insert({16,19});

        cout << ret << endl;
        // 動作受け取り
        pet_move();
        cout << "# " << score_calc() << endl;
    }
}

// 部屋建設
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    input();

    if(m<=6){
        m1();
        return 0;
    }else{
        m2();
        return 0;
    }
}

// cargo run --release --bin tester ./a.out < ./in/0000.txt > ./out/0000.txt