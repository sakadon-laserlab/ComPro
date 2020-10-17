#include<bits/stdc++.h>
using namespace std;

int main() {
    unsigned long X,Y,A,B;cin>>X>>Y>>A>>B;
    unsigned long ex = 0;
    unsigned long now = X;
    unsigned long cnt = 0;
    while(now*(A-1)<B && now*A < Y) {
        now *= A;
        cnt++;
    }
    ex = cnt + (Y - now)/B;
    if ((Y - now) % B  == 0) ex--;

    cout<<ex<<endl;
}