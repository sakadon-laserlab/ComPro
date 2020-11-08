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

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void myFunc (vector<vector<int>> &G, ll now_x, ll now_y, int muki) {
    G[now_y][now_x] = 3; //bright
    ll next_x = now_x + dx[muki];
    ll next_y = now_y + dy[muki];
    if (next_x>=G[0].size() or next_y>=G.size() or next_x<0 or next_y<0 or G[next_y][next_x]==2 or G[next_y][next_x]==1) return;
    else myFunc(G, next_x, next_y, muki);
}

int main() {
    ll  h, w, n, m; cin>>h>>w>>n>>m;
    vector<vector<int>> G(h, vector<int>(w,0));
    REP(i,n){
        ll x,y;cin>>x>>y;
        G[x-1][y-1] = 1; //light
    }
    REP(i,m){
        ll x,y;cin>>x>>y;
        G[x-1][y-1] = 2; //block
    }

    REP(i,h)REP(j,w) {
        if (G[i][j] == 1) {
            REP(k,4) myFunc(G,j,i,k);
        }
    }

    ll ans=0;
    REP(i,h)REP(j,w) if (G[i][j] == 1 or G[i][j] == 3) ans++;

    cout << ans << endl;;
}