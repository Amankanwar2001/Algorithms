#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll a,ll b,ll mod){
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
int main(){
	const int mod=1e9+7;
    ll x,a,n,c;
	while(cin>>x>>a>>n>>c and (x+a+n+c)!=0){
		ll res=x;
		for(int i=0;i<n;i++){
			res=((res-1)*a)%c;
		}

		res=(res)%c;
                if(res<0)res+=c;
		cout<<res<<endl;
	}
	return 0;
}