#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
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

bool linear(ll a ,ll b,ll c,ll &x,ll &y){
	ll d=exgcd(a,b,x,y);
	if(c%d!=0)return false;
	ll k=c/d;
	x=x*k,y=y*k;
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll a,b,c;
    cin>>a>>b>>c;
    ll x=0,y=0;
    // exgcd(a,b,x,y);
    if(linear(a,b,c,x,y)==true){
        cout<<x<<" "<<y<<endl;
    }    
}