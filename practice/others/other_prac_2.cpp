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
    ll H, W; cin >> H >> W;
    ll ans = 0;
    VS G;
    VVL map(H, VL(W, 0));
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    REP(i, H) {
        string tmp;cin >> tmp;
        REP(j, tmp.length()) if (tmp[j] == '#') map[i][j] = 1;
    }

    REP(i, H) REP(j, W) {
        if (map[i][j] == 0) continue;
        ans += 4;
        REP(k, 4) {
            ll nx = j + dx[k];
            ll ny = i + dy[k];
            if (nx<0 or nx>=W or ny<0 or ny>=H) continue;
            else if (map[ny][nx] == 1) ans--;
        }
    }

    cout << ans << endl;
}