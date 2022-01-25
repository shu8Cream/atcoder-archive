/**
*    author:  shu8Cream
*    created: 25.01.2022 12:18:07
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int deg,dis; cin >> deg >> dis;
    deg*=10;
    string dir;
    if(1125<=deg && deg<3375) dir = "NNE";
    else if(3375<=deg && deg<5625) dir = "NE";
    else if(5625<=deg && deg<7875) dir = "ENE";
    else if(7875<=deg && deg<10125) dir = "E";
    else if(10125<=deg && deg<12375) dir = "ESE";
    else if(12375<=deg && deg<14625) dir = "SE";
    else if(14625<=deg && deg<16875) dir = "SSE";
    else if(16875<=deg && deg<19125) dir = "S";
    else if(19125<=deg && deg<21375) dir = "SSW";
    else if(21375<=deg && deg<23625) dir = "SW";
    else if(23625<=deg && deg<25875) dir = "WSW";
    else if(25875<=deg && deg<28125) dir = "W";
    else if(28125<=deg && deg<30375) dir = "WNW";
    else if(30375<=deg && deg<32625) dir = "NW";
    else if(32625<=deg && deg<34875) dir = "NNW";
    else dir = "N";
    double wind = round((double)dis/6.0);
    wind/=10;
    // printf("%.10lf\n", wind);
    int W = 0;
    if(0.0<=wind && wind<=0.2) W = 0;
    else if(0.3<=wind && wind<=1.5) W = 1;
    else if(1.6<=wind && wind<=3.3) W = 2;
    else if(3.4<=wind && wind<=5.4) W = 3;
    else if(5.5<=wind && wind<=7.9) W = 4;
    else if(8.0<=wind && wind<=10.7) W = 5;
    else if(10.8<=wind && wind<=13.8) W = 6;
    else if(13.9<=wind && wind<=17.1) W = 7;
    else if(17.2<=wind && wind<=20.7) W = 8;
    else if(20.8<=wind && wind<=24.4) W = 9;
    else if(24.5<=wind && wind<=28.4) W = 10;
    else if(28.5<=wind && wind<=32.6) W = 11;
    else if(32.7<=wind) W = 12;
    if(W==0) dir="C";
    cout << dir << " " << W << endl;
}