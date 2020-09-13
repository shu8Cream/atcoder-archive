#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i]; 
    //ビット演算で実装すると良い
    //ビット全探索問題
    int ans=0;
    rep(is,1<<h)rep(js,1<<w){ //左シフトで行，列ごとに全列挙　&& 消す行列全探索
        int cnt=0;
        rep(i,h)rep(j,w){ //マス目全検索
            if(is>>i&1) continue; //行が消されてるなら抜ける
            if(js>>j&1) continue; //列が消されてるなら抜ける
            if(s[i][j]=='#') cnt++; //消されず黒ならインクリメント
        }
        if(cnt==k) ans++;
    }
    cout << ans << endl;
}