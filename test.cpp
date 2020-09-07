#include <bits/stdc++.h>
using namespace std;

void test(string (&a)[3]) {
    swap(a[0], a[1]);
}

void test2(int * a[][2]) {
    cout << a[0][0] << endl;
}

int main() {
    string a[3] = {"a", "b", "c"};
    cout << a[0] << a[1] << a[2] << endl;

    test(a);
    cout << a[0] << a[1] << a[2] << endl;

    string b[2][2] = {{"a", "b"}, {"c", "d"}};
    cout << b[1][0] << endl;

    int N; cin >> N;
    int c[N][2];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> c[i][j];
        }
    }
    cout << c[N-1][1] << endl;
    test2(c);
}