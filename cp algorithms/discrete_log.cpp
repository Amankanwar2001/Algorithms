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

ll solve(ll a,ll b,ll m){
    a=a%m;
    b=b%m;

    ll n=(ll)sqrt(m)+1;
    ll an=1;

    //Calculating a^n
    for(int i=0;i<n;i++){
        an=(an*a)%m;
    }
    um<ll,ll>value;

    //Calculating all values of a^(n*i)
    for(ll i=1,cur=an;i<=n;i++){
        if(!value[cur])
            value[cur]=i;
        cur=(cur*an)%m;
    }

    //Calculating (a^j)*b checking for collision
    for(int i=0,cur=b;i<=n;i++){
        if(value[cur]){
            ll ans=value[cur]*n-i;
            if(ans<m)return ans;
        }
        cur=(cur*a)%m;
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        ll a,b,m;
        cin>>a>>b>>m;
        ll ans=solve(a,b,m);
        cout<<ans<<endl;
    }
    return 0;
}