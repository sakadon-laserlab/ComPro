// #include<bits/stdc++.h>
// // #include<iostream>
// // #include<string>
// // #include<vector>
// using namespace std;
// //typedef
// typedef long long ll;
// typedef pair<ll,ll> PLL;
// typedef vector<ll> VL;
// typedef vector<VL> VVL;
// typedef vector<bool> VB;
// typedef vector<VB> VVB;
// typedef vector<string> VS;
// //template
// template<class T> inline bool chmin(T &a, T b) {if (a > b){a = b; return true;} return false;}
// template<class T> inline bool chmax(T &a, T b) {if (a < b){a = b; return true;} return false;}
// //repetition
// #define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
// #define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
// #define REP(i,N) for(int i=0; i<int(N); ++i)
// #define REPS(i,N) for(int i=0; i<=int(N); ++i)
// #define REPD(i,N) for(int i=0; i<int(N); --i)
// //container util
// #define ALL(obj) (obj).begin(), (obj).end()
// #define RALL(obj) (obj).rbegin(), (obj).rend()
// #define PB push_back
// #define MP make_pair
// #define SZ(a) int((a).size())
// #define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
// #define EXIST(s,e) ((s).find(e)!=(s).end())
// #define SORT(c) sort((c).begin(),(c).end())
// //constant
// #define INF 1000000000000 //10^12:∞
// #define MOD 1000000007 //10^9+7
// #define MAXR 100000 //配列の最大のrenge
// //debug
// #define dump(x)  cerr << #x << " = " << (x) << endl;
// #define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

// int main() {
//     string s,t; cin >> s >> t;
//     int dp[310][310] = {0};
//     REP(i,(int)s.size()+1)REP(j,(int)t.size()+1) cout<<dp[i][j];
//     cout<<endl<<(int)s.size()<<endl;;

//     //DPループ
//     REP(i,s.size())REP(j,t.size()) {
//         cout<<dp[i][j]<<endl;
//         if(s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
//         chmax(dp[i+1][j+1], dp[i+1][j]);
//         chmax(dp[i+1][j+1], dp[i][j+1]);
//     }

//     //復元
//     string res = "";
//     int i = (int)s.size(), j = (int)t.size();
//     while (i > 0 && j > 0) {
//         if (dp[i][j] == dp[i-1][j]) i--;
//         else if (dp[i][j] == dp[i][j-1]) j--;
//         else {
//            res = s[i-1] + res;
//            i--;
//            j--; 
//         }
//     }
//     cout<<dp[0][0]<<endl<<dp[1][1]<<endl<<dp[2][2]<<endl;
//     cout << res << endl;
// }

#include <iostream>
#include <string>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL<<60;

// 入力
string s, t;

// DPテーブル
int dp[3100][3100] = {0}; // 初期値も初期条件も 0

int main() {
    cin >> s >> t;

    // DPループ
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            if (s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
            chmax(dp[i+1][j+1], dp[i+1][j]);
            chmax(dp[i+1][j+1], dp[i][j+1]);
        }
    }

    // 復元
    string res = "";
    int i = (int)s.size(), j = (int)t.size();
    while (i > 0 && j > 0)
    {
        // (i-1, j) -> (i, j) と更新されていた場合
        if (dp[i][j] == dp[i-1][j]) {
            --i; // DP の遷移を遡る
        }

        // (i, j-1) -> (i, j) と更新されていた場合
        else if (dp[i][j] == dp[i][j-1]) {
            --j; // DP の遷移を遡る
        }

        // (i-1, j-1) -> (i, j) と更新されていた場合
        else {
            res = s[i-1] + res; // このとき s[i-1] == t[j-1] なので、t[j-1] + res でも OK
            --i, --j; // DP の遷移を遡る
        }
    }
    cout << res << endl;
}