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
		}
        a=(a*a)%mod;
		b=b/2;
	}
	return res;
}
ll inv(ll a,ll m){
    return power(a,m-2,m);
}
ll exgcd(ll a,ll b,ll&x,ll&y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}

	ll x1,y1;
	ll d=exgcd(b,a%b,x1,y1);
	x=y1;
	y=x1-y1*(a/b);
	return d;
}

ll inverse(ll a,ll m){
    ll x=0,y=0;
    ll g=exgcd(a,m,x,y);
    if(g!=1){
        return -1;
    }

    else{
        x=(x%m+m)%m;
        return x;
    }
}

ll crt (vpl &v){   
    ll ans=0;
    ll n=v.size();

    ll m=1;  //m=p1*p2*p3.....
    for(int i=0;i<n;i++){
        m*=v[i].first;
    }

    for(int i=0;i<n;i++){
        ll t=1;
        for(ll j=0;j<i;j++){
            t*=v[j].first;
            t*=inv(v[j].first,v[i].second);
            t%=m;
        }

        ans+=(t*(v[i].second+m-ans))%m;
        ans%=m;
    }
    return ans;
}
int main(){
    ll n;
    cin>>n;

    vector<pair<ll,ll>>v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }

    cout<<crt(v);
    return 0;
}