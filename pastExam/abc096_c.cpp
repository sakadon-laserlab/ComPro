#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0; i<(int)(N); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()

int main() {
    int H, W; cin >> H >> W;
    vector<string> grid(H);
    rep(i,H) cin >> grid[i];
    string res = "Yes";

    rep(i,H)rep(j,W) {
        if (grid[i][j] == '.') continue;
        res = "No";
        for (int k = -1; k <= 1; ++k){
            if (i + k < 0 || i + k >= H) continue;
            for (int l = -1; l <= 1; ++l){
                if (k!=0 && l!=0) continue;
                if (j + l < 0 || j + l >= W) continue;
                if (k == 0 && l == 0) continue;
                if (grid[i + k][j + l] == '#') res = "Yes";
            }
        }
        if (res == "No") break;
    }
    cout << res;
}