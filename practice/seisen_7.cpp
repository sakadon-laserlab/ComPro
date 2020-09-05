#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int tmp = 0;
    int res = 0;
    vector<int> A;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }

    int num[100] = {0};
    for (int i = 0; i < N; i++)
        num[A.at(i)]++;
    
    for (int i : num) 
        if (i > 0) res++;

    cout << res << endl;
}