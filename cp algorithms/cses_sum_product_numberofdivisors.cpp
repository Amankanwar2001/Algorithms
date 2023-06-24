#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod =1e9 +7;
const int N = 1e6 + 100;
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
 
ll inverse(ll a,ll p){
	return power(a,p-2);
}
 
int findSum(int n, int p) {
	return (n & 1 ? (n + 1) / 2 * n : n / 2 * (n + 1)) % p;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	ll num=1;
    ll sum=1;
	ll prod=1;
	ll prime=1;
	for(int i=0;i<n;i++){
		ll x,k;
		cin>>x>>k;
		num=num*(k+1)%mod;
		sum=sum*(power(x,k+1)-1)%mod*power(x-1,mod-2)%mod;
		prod=power(prod,k+1)*power(power(x,k*(k+1)/2),prime)%mod;
		prime=prime*(k+1)%(mod-1);
	}
 
    cout<<num<<" "<<sum <<" "<<prod;
    return 0;
}