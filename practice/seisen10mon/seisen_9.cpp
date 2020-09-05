#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    string divide[4] = {"dream", "dreamer", "erase", "eraser"};
    cin >> S;

    reverse(S.begin(), S.end());
    for (string &s : divide) reverse(s.begin(), s.end()); //遅い?
    //for (int i = 0; i < 4; i++) reverse(divide[i].begin(), divide[i].end());

    bool can = true;
    for (int i = 0; i < S.size();) {
        bool can2 = false; // 4個の文字列のどれかでdivideできるか
        for (int j = 0; j < 4; j++) {
            string d = divide[j];
            if (S.substr(i, d.size()) == d) {
                can2 = true;
                i += d.size();
            }
        }
        if (!can2) {
            can = false;
            break;
        }
    }

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
}