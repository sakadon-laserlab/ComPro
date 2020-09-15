#include<bits/stdc++.h>
using namespace std;
//typedef
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
//repetition
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
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
    int N; cin >> N;
    VVI D(N,VI(N));
    REP(i,N)REP(j,N) cin >> D[i][j];

    //累積和
    VVI S(N+1, VI(N+1, 0));
    REP(i,N)REP(j,N) S[i+1][j+1] = S[i+1][j] + S[i][j+1] - S[i][j] + D[i][j];  

    //全ての長方形区域の面積を集計
    VI val(N*N+1, 0); // val[v] := 面積が v の長方形領域の総和の最大値
    REP(x1,N)REP(x2,N+1)REP(y1,N)REP(y2,N+1) {
        int area = (x2 - x1) * (y2 - y1);
        int sum = S[x2][y2] - S[x1][y2] - S[x2][y1] + S[x1][y1];
        val[area] = max(val[area], sum);
    }

    //ちゃんと集計 val[v] := 面積が v の長方形領域の総和の最大値
    REP(i,N*N) val[i+1] = max(val[i], val[i+1]);

    //クエリに答える
    int Q; cin >> Q;
    REP(i,Q) {
        int p; cin >> p;
        cout << val[p] << endl;
    }
}