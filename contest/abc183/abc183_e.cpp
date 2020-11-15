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

void dfs(VS G, ll x, ll y, ll &ans) {
    ll cnt_1=0,cnt_2=0,cnt_3=0;
    ll h = G.size();
    ll w = G[0].size();

    while(true) {
        cnt_1++;
        if (x+cnt_1<w) {
            ll nx = x + cnt_1;
            ll ny = y;
            if (nx==w-1 and ny==h-1) {
                ans++;
                ans %= MOD;              
                break;
            }
            if (G[ny][nx] == '#') break;
            dfs(G, nx, ny, ans);
        }
        else break;
    }

    while(true) {
        cnt_2++;
        if (y+cnt_2<h) {
            ll nx = x;
            ll ny = y + cnt_2;
            if (nx==w-1 and ny==h-1) {
                ans++;
                ans %= MOD;
                break;
            }
            if (G[ny][nx] == '#') break;
            dfs(G, nx, ny, ans);
        }
        else break;
    }

    while(true) {
        cnt_3++;
        if (x+cnt_3<w and y+cnt_3<h) {
            ll nx = x + cnt_3;
            ll ny = y + cnt_3;
            if (nx==w-1 and ny==h-1) {
                ans++;
                ans %= MOD;
                break;
            }
            if (G[ny][nx] == '#') break;
            dfs(G, nx, ny, ans);
        }
        else break;
    }
}


int main() {
    ll h,w;cin>>h>>w;
    VS G; REP(i,h){string tmp;cin>>tmp;G.PB(tmp);}
    ll ans = 0;

    dfs(G, 0, 0, ans);

    cout << ans << endl;
}