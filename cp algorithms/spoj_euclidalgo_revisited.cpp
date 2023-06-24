#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long mod=1000000007;

void multiply(ll F[2][2],ll M[2][2]){
    long long x =((F[0][0]*M[0][0])%mod +(F[0][1]*M[1][0])%mod)%mod;
    long long y =((F[0][0]*M[0][1])%mod +(F[0][1]*M[1][1])%mod)%mod;
    long long z =((F[1][0]*M[0][0])%mod +(F[1][1]*M[1][0])%mod)%mod; 
    long long w =((F[1][0]*M[0][1])%mod +(F[1][1]*M[1][1])%mod)%mod;  

    F[0][0]=x;
    F[0][1]=y;
    F[1][0]=z;
    F[1][1]=w;
}
void power(ll F[2][2],ll n){
    if(n==0 or n==1)return;
    ll M[2][2]={{1,1},{1,0}};
    power(F,n/2);
    multiply(F,F);
    
    if(n&1){
        multiply(F,M);
    }
}
ll fib(ll n){
    if(n==0)return;
    ll F[2][2]={{1,1},{1,0}};
    power(F,n-1);
    return F[0][0];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==0)cout<<0<<'\n';
        else if(n==1)cout<<2<<'\n';
        else cout<<fib(n+3)%mod<<'\n';
    }
    return 0;
}