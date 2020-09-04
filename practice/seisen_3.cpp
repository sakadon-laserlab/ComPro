#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    vector<int> A;
    int tmp = 0;
    int res = 0;

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0; i < N; i++){
        tmp = 0;
        while (true) {
            if (A.at(i) == 0 || A.at(i) % 2 == 1) break;
            tmp++;
            A.at(i) /= 2;
        }
        if (i == 0) res = tmp;
        else res = min(res, tmp);
    }

    cout << res << endl;
}