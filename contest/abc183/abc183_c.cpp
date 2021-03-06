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

void dfs(VL houmonzumi, ll &ans, VVL times, ll N, ll now_time, ll K, ll now) {
    houmonzumi[now] = 1;

    if (find(ALL(houmonzumi), 0) == houmonzumi.end()) {
        if (now_time + times[now][0] == K) ans++;
        return;
    }

    REP(i,N) {
        if (houmonzumi[i] == 0) 
            dfs(houmonzumi, ans, times, N, now_time+times[now][i], K, i);
    }
}

int main() {
    ll N,K;cin>>N>>K;
    VVL times(N, VL(N, 0));
    REP(i,N)REP(j,N) cin>>times[i][j];
    ll ans = 0;
    
    VL houmonzumi(N, 0);
    houmonzumi[0] = 1;
    ll now_time = 0;

    dfs(houmonzumi, ans, times, N, now_time, K, 0);

    cout << ans << endl;
}