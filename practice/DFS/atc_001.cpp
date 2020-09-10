#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
#define REPD(i,N) for(int i=0; i<int(N); --i)
#define PB push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7
#define MAXR 100000 //配列の最大のrenge

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void dfs(vector<string> G, int x, int y, vector<vector<bool>> &seen){
    seen[x][y] = true;

    REP(i,4) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny >= G.size() || nx < 0 || nx >= G[0].length()) continue;
        if (G[nx][ny] == '#') continue;
        if (seen[nx][ny]) continue;

        dfs(G,nx,ny,seen);
    }
}

int main() {
    int H, W; cin>>H>>W;
    vector<string> G;
    REP(i,H) {
        string tmp; cin >> tmp;
        G.PB(tmp);
    }

    int s[2],g[2];
    REP(i,H)REP(j,W) {
        if (G[i][j] == 's') {s[0]=i; s[1]=j;}
        if (G[i][j] == 'g') {g[0]=i; g[1]=j;}
    }

    vector<vector<bool>> seen(H, vector<bool>(W,false));
    seen[s[0]][s[1]] = true;
    dfs(G,s[0],s[1],seen);

    if (seen[g[0]][g[1]]) cout << "Yes";
    else cout << "No";
}