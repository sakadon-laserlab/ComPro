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
    ll r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
    int ans=3;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    REP(i,3)REP(j,4) {
        int tmp_r1 = r1 + (i+1)*dx[j];
        int tmp_c1 = c1 + (i+1)*dy[j];
        if (tmp_r1+tmp_c1==r2+c2 or tmp_r1-tmp_c1==r2-c2 or abs(tmp_r1-r2)+abs(tmp_c1-c2)<=3) {ans = 2;}
    }
    if (r1%2==r2%2 and c1%2==c2%2) {ans = 2;}
    else if (r1%2!=r2%2 and c1%2!=c2%2) ans = 2;
    if (c1==c2 and r1==r2) ans = 0;
    else if (r1+c1==r2+c2 or r1-c1==r2-c2 or abs(r1-r2)+abs(c1-c2)<=3) ans = 1;

    cout << ans << endl;;
}