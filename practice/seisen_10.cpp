#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    vector<int> t, x, y;
    cin >> N;
    t.push_back(0);
    x.push_back(0);
    y.push_back(0);

    int tmp_t, tmp_x, tmp_y;
    for (int i = 0; i < N; i++) {
        cin >> tmp_t >> tmp_x >> tmp_y;
        t.push_back(tmp_t);
        x.push_back(tmp_x);
        y.push_back(tmp_y);
    }

    bool can = true;
    for (int i = 0; i < N; i++) {
        int dt = t.at(i+1) - t.at(i);
        int dist = abs(x.at(i+1) - x.at(i)) + abs(y.at(i+1) - y.at(i));
        if (dt < dist) can = false;
        if (dist%2 != dt%2) can = false;
    }

    if (can) cout << "Yes" <<endl;
    else cout << "No" << endl;
}