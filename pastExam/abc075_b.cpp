#include<bits/stdc++.h>
using namespace std;

void count_bomb(int H, int W, string A[][1], int p[2]) {
    int tmp = 0;
    for (int i = -1; i <= 1; i++) {
        if (p[0] + i < 0 || p[0] + i == H) continue;
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (p[1] + j < 0 || p[1] + j == W) continue;
            if (A[p[0] + i][p[1] + j] == "#") tmp += 1;
        }
    }
    A[p[0]][p[1]] = to_string(tmp);
}

int main() {
    int H, W; cin >> H >> W;

    string A[H][W];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    cout << A[0][0];
}
