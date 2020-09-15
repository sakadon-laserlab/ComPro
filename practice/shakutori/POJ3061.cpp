#include<bits/stdc++.h>
using namespace std;
//typedef
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<ll> VL;
typedef vector<VL> VVL;
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
    int Q; cin >> Q;

    REP(i,Q) {
        int n; cin >> n;
        ll x; cin >> x;
        VL a(n); REP(j,n) cin >> a[j];
        int res = n+1;
        int right = 0;
        ll sum = 0;
        REP(l,n) {
            while (right < n && sum < x) {
                sum += a[right];
                right++;
            }

            if (sum < x) break;
            res = min(res, right - l);

            if (right == l) right++;
            else sum -= a[l];
        }

        if (res < n+1) cout<<res<<endl;
        else cout<<0<<endl;
    }
}