#include<bits/stdc++.h>
using namespace std;
//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//macro definition
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ll long long
#define db long double
#define ull unsigned long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repk(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i++ : i--)
#define bit(x) __builtin_popcount(x)
#define bitll(x) __builtin_popcountll(x)
#define popb pop_back
#define pb push_back
#define eb emplace_back
#define ub upper_bound
#define lb lower_bound
#define ff first
#define ss second
#define um unordered_map
#define om ordered_map
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define precision(x, y) fixed << setprecision(y) << x
#define PI 3.1415926535897932384626
#define sz(x) ((ll)(x).size())
#define present(b, a) ((a).find((b)) != (a).end())  //if b is present in a
const ll mod = 1e9 + 7; //1000000007
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;
const db epsilon = 1e-12;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef pair<db, db> pd;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
ll power(ll a,ll b){
	a=a%mod;
	ll res=1;
	while(b){
		if(b&1){
			res=(res*a)%mod;
		}
        a=(a*a)%mod;
		b=b/2;
	}
	return res%mod;
}

void solve(){
 
}
int main(){
   ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1,j;i<=n;i=j){
        ll q=n/i;
        j=n/q +1;

        ll rangesum_uptojminus1=((((j%mod)*((j-1)%mod))%mod)*power(2,mod-2))%mod;
        ll rangesum_uptoiminus1=((((i%mod)*((i-1)%mod))%mod)*power(2,mod-2))%mod;
        ll rangewithquotientq=(rangesum_uptojminus1-rangesum_uptoiminus1+mod)%mod;
        ans=(ans+(q%mod)*rangewithquotientq)%mod;
    }

    cout<<ans<<endl;
    return 0;
}