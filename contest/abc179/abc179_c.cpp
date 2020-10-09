#include<bits/stdc++.h>
using namespace std;
//typedef
typedef long long ll;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
//template
template<class T> inline bool chmin(T &a, T b) {if (a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) {if (a < b){a = b; return true;} return false;}
//repetition
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
#define REPS(i,N) for(int i=0; i<=int(N); ++i)
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

void my_prime_factorize(ll n, map<ll,ll> &prime) {
    if(n<=1) return;
    ll l=sqrt(n);
    FOR(i,2,l+1){
        if(n%i==0){
        my_prime_factorize(i,prime);my_prime_factorize(ll(n/i),prime);return;
        }
    }

    prime[n]++;return;
}

int main() {
    ll N; cin >> N;
    ll res = 1;

    FOR(j,1,N-1) {
        map<ll,ll> prime;
        ll tmp = N - j;
        ll tmp2 = 1;

        my_prime_factorize(tmp,prime);
        for (auto dt : prime) {
            tmp2 *= (dt.second + 1);
        }
        res += tmp2;
    }

    cout << res << endl;
}