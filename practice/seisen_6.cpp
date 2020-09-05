#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int tmp;
    int Alice;
    int Bob;
    vector<int> A;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }

    sort(A.begin(),A.end(),greater<int>());

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            Alice += A.at(i);
        }
        else
            Bob += A.at(i);
    }
    cout << Alice - Bob << endl;
}