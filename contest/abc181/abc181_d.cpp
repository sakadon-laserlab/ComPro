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

int main() {
    ll s;cin >> s;
    string ans = "No";

    if (s < 10) {
        if (s == 8) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }

    string S = to_string(s);

    if (s<100) if (s==16 or s==24 or s==32 or s==48 or s==56 or s==64 or s==72 or s==88 or s==96) ans = "Yes";

    else if(
        ((S.find('2') != string::npos) and (S.find('4') != string::npos)) or
        ((S.find('4') != string::npos) and (S.find('8') != string::npos)) or
        ((S.find('6') != string::npos) and (S.find('4') != string::npos)) or
        (count(S.cbegin(), S.cend(), '8') >= 2)
    ) ans = "Yes";

    cout << ans << endl;
}