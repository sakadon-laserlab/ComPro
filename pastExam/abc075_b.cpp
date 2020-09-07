#include<bits/stdc++.h>
using namespace std;

int bombCount(int h, int w, vector<vector<char>> vv, int x, int y) {
    int cnt = 0;

    for (int i = -1; i <= 1; i++) {
        if (x + i < 0 || x + i > h) continue;
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (y + j < 0 || y + j > w) continue;
            if (vv[x + i][y + j] == '#') cnt += 1;
        }
    }

    return cnt;
} 

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> grid;
    for (int i = 0; i < H; i++) {
        vector<char> tmp_raw;
        for (int j = 0; j < W; j++) {
            char tmp;
            cin >> tmp;
            tmp_raw.push_back(tmp);
        }
        grid.push_back(tmp_raw);
    }
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '.') {
                int cnt = 0;
                cnt = bombCount(H, W, grid, i, j); 
                grid[i][j] = '0' + cnt;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}