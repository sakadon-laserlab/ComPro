#include<bits/stdc++.h>
using namespace std;
//typedef
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
//repetition
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
#define REPD(i,N) for(int i=0; i<int(N); --i)
//container util
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//constant
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7
#define MAXR 100000 //配列の最大のrenge
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main() {
    //エラトステネスのふるい
    int MAX = 101010;
    VI is_prime(MAX, 1);
    is_prime[0]=0; is_prime[1]=0;
    REP(i,MAX) {
        if(!is_prime[i]) continue;
        for(int j = 2*i; j<MAX; j+=i) is_prime[j] = 0;
    }

    //2017like?
    VI a(MAX,0);
    REP(i,MAX) {
        if (i % 2 == 0) continue;
        if (is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
    }

    //累積和
    VI s(MAX+1,0);
    REP(i,MAX) s[i+1] = s[i] + a[i];

    //クエリ処理
    int Q; cin >> Q;
    REP(i,Q) {
        int l, r; cin >> l >> r;
        r++;

        cout << s[r] - s[l] << endl;
    }

}