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

void dfs(VS G, int x, int y, VVB &seen) {
    seen[x][y] = true;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    REP(i,4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx<0 || nx>=10 || ny<0 || ny>=10) continue;
        if (G[nx][ny] == 'x') continue;
        if (seen[nx][ny] == true) continue;
        dfs(G, nx, ny, seen);
    }

}

int main() {
    VS G(10);
    REP(i,10) cin>>G[i];

    REP(i,10)REP(j,10) {
        VVB seen(10,vector<bool>(10,false));
        if (G[i][j] == 'o') continue;
        G[i][j] = 'o';
        bool onepeace = true;
        bool res = true;
        REP(k,10)REP(l,10) {
            if (G[k][l] == 'o' && seen[k][l] == false) {
                if (onepeace == false) {
                    res = false;
                    break;
                }
                onepeace = false;
                dfs(G, k, l, seen); 
            }
        }
        if (res == true) {

            cout << "YES" << endl;
            return 0;
        }
        G[i][j] = 'x';
    }
    cout << "NO" << endl;
}