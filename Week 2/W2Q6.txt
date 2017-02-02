#include<stdio.h>
#define ll long long
ll an=0;

ll mypow(ll a,ll b){
    ll ans=1;
    int i;
    for(i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}

void rec(ll n,ll k){
    if(k==0) {an++;return;}
    ll sta=n/k;
    
//    printf("%lld,%lld,%lld\n",n,k,sta);
    ll sz=k;  
    ll rwl=n%k;
    ll da=0;
    while(sz>1){da++;sz/=10;}
    if(sta==7){
        an+=(mypow(3,(da)));
        rec(rwl,k/10);
        return;
    }
    if(sta==1){
        rec(rwl,k/10);
        return;
    }
    if(sta==9){
        an+=2*(mypow(3,(da)));
        rec(rwl,k/10);
        return;
    }
    if(sta==8){
        an+=2*(mypow(3,(da)));
        return;
    }
    if(sta==0){
        return;
    }
    if(sta>=3 && sta<=6){
        an+=(mypow(3,(da)));
        return;
    }
}

int main()
{
	long long int n,k=1;
    scanf("%lld",&n);
    while(k<=n)
    {
        k*=10;
    }
    k/=10;
    rec(n,k);
    while(k>1){
        rec(k-1,k/10);
        k/=10;
    }
    printf("%lld",an);
	return 0;
}
