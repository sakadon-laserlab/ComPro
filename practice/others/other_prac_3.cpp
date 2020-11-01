#include<bits/stdc++.h>
using namespace std;
//typedef
typedef long long ll;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
//template
template<class T> inline bool chmin(T &a, T b) {if (a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) {if (a < b){a = b; return true;} return false;}
//repetition
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
#define REPS(i,N) for(int i=0; i<=int(N); ++i)
#define REPD(i,N) for(int i=0; i<int(N); --i)
//container util
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//constant
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7
#define MAXR 100000 //配列の最大のrenge
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main() {
    ll now_x, now_y; cin >> now_x >> now_y;
    ll move[4]; REP(i,4) cin >> move[i];
    ll num_comand; cin >> num_comand;
    ll houkou = 0; // houkou % 4 = 0:上 1:右 2:下 3:左

    REP(i,num_comand) {
        char temp_comand, temp_houkou; cin >> temp_comand >> temp_houkou;
        if (temp_comand == 't') {
            if (temp_houkou == 'R') houkou += 1;
            if (temp_houkou == 'B') houkou += 2;
            if (temp_houkou == 'L') houkou += 3;
        }
        if (temp_comand == 'm') {
            if (temp_houkou == 'F') {
                if (houkou%4 == 0) now_y+=move[0];
                if (houkou%4 == 1) now_x+=move[0];
                if (houkou%4 == 2) now_y-=move[0];
                if (houkou%4 == 3) now_x-=move[0];
            }
            if (temp_houkou == 'R') {
                if (houkou%4 == 0) now_x+=move[1];
                if (houkou%4 == 1) now_y-=move[1];
                if (houkou%4 == 2) now_x-=move[1];
                if (houkou%4 == 3) now_y+=move[1];
            }
            if (temp_houkou == 'B') {
                if (houkou%4 == 0) now_y-=move[2];
                if (houkou%4 == 1) now_x-=move[2];
                if (houkou%4 == 2) now_y+=move[2];
                if (houkou%4 == 3) now_x+=move[2];
            }
            if (temp_houkou == 'L') {
                if (houkou%4 == 0) now_x-=move[3];
                if (houkou%4 == 1) now_y+=move[3];
                if (houkou%4 == 2) now_x+=move[3];
                if (houkou%4 == 3) now_y-=move[3];
            }
        }
    }

    cout << now_x << " " <<  now_y << endl;
}