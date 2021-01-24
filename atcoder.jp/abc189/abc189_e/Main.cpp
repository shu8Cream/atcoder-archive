/**
*    author:  shu8Cream
*    created: 23.01.2021 20:47:09
**/

#include <bits/stdc++.h>
using namespace std;
//#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define drep(i,cc,n) for(int i=(cc);i<=(n);++i)
#define rep(i,n) drep(i,0,n-1)
#define sz(s) (int)(s.size())
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

template<typename T>
struct mat {
    // 行列m
    vector<vector<T>> m;
    // コンストラクタ:第1引数⇒行数、第2引数⇒列数、第3引数⇒初期値
    mat():m(vector<vector<T>>()){}
    mat(int h,int w):m(vector<vector<T>>(h,vector<T>(w))){}
    mat(int h,int w, T d):m(vector<vector<T>>(h,vector<T>(w,d))){}
    // 添字演算子
    vector<T> operator[](const int i) const {return m[i];} //読み取り
    vector<T>& operator[](const int i){return m[i];} //書き込み
    // 行数・列数
    int nrow = sz(m);
    int ncol = sz(m[0]);
    // 行列同士の演算
    mat& operator=(const mat& a){return *a;}
    mat& operator+=(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] += a[i][j]; return *this;}
    mat& operator-=(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] -= a[i][j]; return *this;} 
    mat& operator*=(const mat& a){assert(ncol == a.nrow);mat<T> m2(nrow, a.ncol, 0);rep(i,nrow)rep(j,a.ncol)rep(k,ncol)m2[i][j] += m[i][k]*a[k][j];ncol = a.ncol;rep(i,nrow)m[i].resize(ncol);rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j]; return *this;}
    mat operator+(const mat& a) const { return mat(*this) += a;}
    mat operator-(const mat& a) const { return mat(*this) -= a;}
    mat operator*(const mat& a) const { return mat(*this) *= a;}
    bool operator==(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);bool flg = true;rep(i,nrow)rep(j,ncol)if(m[i][j] != a[i][j])flg = false; return flg;}
    // 行列とスカラの演算
    mat& operator+=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] += a;return *this;}
    mat& operator-=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] -= a;return *this;}
    mat& operator*=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] *= a;return *this;}
    mat& operator/=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] /= a;return *this;}
    mat operator+(const T& a) const { return mat(*this) += a;}
    mat operator-(const T& a) const { return mat(*this) -= a;}
    mat operator*(const T& a) const { return mat(*this) *= a;}
    mat operator/(const T& a) const { return mat(*this) /= a;}
    // 回転（degの数だけ時計回りに90度回転）
    mat& rot(int deg){
        mat<T> m2(ncol, nrow);
        if(deg == 1 || deg == 3){
            if(deg == 1)rep(i,nrow)rep(j,ncol)m2[j][nrow -i -1] = m[i][j];
            if(deg == 3)rep(i,nrow)rep(j,ncol)m2[ncol -j -1][i] = m[i][j];
            swap(ncol,nrow); // 列数と行数を入れ替える
            m.resize(nrow);rep(i,nrow)m[i].resize(ncol); //リサイズ
        }
        if(deg == 2)rep(i,nrow)rep(j,ncol)m2[nrow -i -1][ncol -j -1] = m[i][j];
        rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j];
        return *this;
    }
    // 標準出力
    void show(){
        rep(i,nrow)rep(j,ncol){
            if(j != 0)cout << " ";
            cout << m[i][j];
            if(j==ncol-1)cout << endl;
        }
        return ;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    int m; cin >> m; 
    vector<mat<ll>> afin;
    rep(i,m){
        int op; cin >> op;
        mat<ll> ma(3,3,0);
        if(op==1){
            ma[0][1]=1;
            ma[1][0]=-1;
            ma[2][2]=1;
            afin.push_back(ma);
        }
        if(op==2){
            ma[0][1]=-1;
            ma[1][0]=1;
            ma[2][2]=1;
            afin.push_back(ma);
        }
        if(op==3){
            int p; cin >> p;
            ma[0][0]=-1;
            ma[0][2]=2*p;
            ma[1][1]=1;
            ma[2][2]=1;
            afin.push_back(ma);
        }
        if(op==4){
            int p; cin >> p;
            ma[0][0]=1;
            ma[1][2]=2*p;
            ma[1][1]=-1;
            ma[2][2]=1;
            afin.push_back(ma);
        }
    }
    vector<mat<ll>> afinR;
    mat<ll> ini(3,3,0);
    ini[0][0]=1;
    ini[1][1]=1;
    ini[2][2]=1;
    afinR.push_back(ini);
    rep(i,m){
        afinR.push_back(afin[i]*afinR[i]);
    }
    int q; cin >> q;
    rep(i,q){
        int a,b; cin >> a >> b; b--;
        mat<ll> tmp(3,1,1);
        tmp[0][0]=x[b]; tmp[1][0]=y[b];
        mat<ll> ans = afinR[a]*tmp;
        cout << ans[0][0] << " " << ans[1][0] << endl;
    }
}