/**
*    author:  shu8Cream
*    created: 02.03.2021 13:45:23
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

const vector<string> key = {"AKIHABARA", "KIHBR", "KIHBRA", "KIHBAR", "KIHABR","AKIHBR",
                    "AKIHABR","AKIHBAR","AKIHBRA","KIHABAR","KIHABRA","KIHBARA",
                    "AKIHABAR","AKIHABRA","AKIHBARA","KIHABARA"};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    bool ok = false;
    rep(i,key.size()){
        if(s==key[i]) ok=true;
    }
    cout << (ok ? "YES" : "NO") << endl;
}