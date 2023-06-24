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

ll power(ll a,ll b,ll mod){
	a=a%mod;
	ll res=1;
	while(b>0){
		if(b&1){
			res=(res*a)%mod;
            b--;
		}
        a=(a*a)%mod;
		b=b/2;
	}
	return res;
}

ll generator(ll p){
    vl fact;
    // p is prime hence phi=p-1, for non-prime p also calulate phi(p)
    ll phi=p-1,n=phi;  
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            fact.pb(i);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n>1){
        fact.pb(n);
    }
    for(ll res=2;res<=p;res++){
        bool flag=true;
        for(size_t i=0;i<fact.size() and flag;i++){
            flag=flag&power(res,phi/fact[i],p)!=1;
        }
        if(flag)return res;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<generator(47);
    return 0;
}