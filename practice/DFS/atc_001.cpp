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

void dfs(vector<vector<string>> G, int p[2], vector<vector<bool>> &seen){

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

}