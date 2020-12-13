#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using Graph = vvi;

int c;
vvi p(52, vi(52));

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

//そのマスの４近傍で何個掘削済みか
int how_open(int x, int y, vvi seen){
    int cnt=0;
    rep(i,4){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(seen[nx][ny]==1) cnt++;
    }
    return cnt;
}

//そのマスのコスト計算
int cost(int x, int y,vvi seen){
    return c/how_open(x,y,seen);
}

int search25(int x, int y, vvi seen){
    int koumyaku = 0;
    for(int i=-2; i<=2; i++){
        for(int j=-2; j<=2; j++){
            int nx = x + i;
            int ny = y + j;
            if(nx<1 || nx>50 || ny<1 || ny>50) continue;
            if(seen[nx][ny]==1) continue;
            koumyaku+=p[nx][ny];
        }
    }
    return koumyaku;
}

int main(){
    //入力の受け取り
    cin >> c;
    rep(i,50)rep(j,50) cin >> p[i+1][j+1];

    //掘削済みかどうかを保持する配列
    vvi seen(52, vi(52));
    rep(i,52){
        seen[i][0]=1;
        seen[0][i]=1;
        seen[51][i]=1;
        seen[i][51]=1;
    }

    //純利益とそのマスの位置を保持する
    priority_queue<pair<int,P>> pq;
    //25近傍で鉱脈を探す
    priority_queue<pair<int,P>> koumyakuSearch;

    //x軸1の正方形の左の辺
    rep(i,50){
        int nx=1; int ny=1+i;
        pq.push(make_pair(p[nx][ny]-cost(nx,ny,seen), P{nx,ny}));
        koumyakuSearch.push(make_pair(search25(nx,ny,seen), P{nx,ny}));
    }
    //y軸1の正方形の上の辺
    rep(i,50){
        int nx=1+i; int ny=1;
        pq.push(make_pair(p[nx][ny]-cost(nx,ny,seen), P{nx,ny}));
        koumyakuSearch.push(make_pair(search25(nx,ny,seen), P{nx,ny}));
    }
    //x軸50の正方形の右の辺
    rep(i,50){
        int nx=50; int ny=1+i;
        pq.push(make_pair(p[nx][ny]-cost(nx,ny,seen), P{nx,ny}));
        koumyakuSearch.push(make_pair(search25(nx,ny,seen), P{nx,ny}));
    }
    //y軸1の正方形の下の辺
    rep(i,50){
        int nx=1+i; int ny=50;
        pq.push(make_pair(p[nx][ny]-cost(nx,ny,seen), P{nx,ny}));
        koumyakuSearch.push(make_pair(search25(nx,ny,seen), P{nx,ny}));
    }

    int cnt=0;
    vector<P> ans;
    int score=0;

    while(cnt<1500){
        auto koumyakutop = koumyakuSearch.top();
        koumyakuSearch.pop();
        if(koumyakutop.first>=0){
            auto top = koumyakutop.second;
            if(seen[top.first][top.second]==1) continue;
            score+=p[top.first][top.second]-cost(top.first,top.second,seen);
            seen[top.first][top.second]=1;
            ans.push_back({top.first,top.second});
            cnt++;
            rep(i,4){
                int nx = top.first+dx[i];
                int ny = top.second+dy[i];
                if(nx<1 || nx>50 || ny<1 || ny>50) continue;
                if(seen[nx][ny]==1) continue;
                pq.push(make_pair(p[nx][ny]-cost(nx,ny,seen), P{nx,ny}));
                koumyakuSearch.push(make_pair(search25(nx,ny,seen), P{nx,ny}));
            }
        }
    }

    //結果出力
    cout << ans.size() << endl;
    for(auto v : ans){
        cout << v.first-1 << " " << v.second-1 << endl;
    }
}