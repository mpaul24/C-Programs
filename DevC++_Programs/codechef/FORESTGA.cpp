#include<stdio.h>
#define M 100011
#define BIG 1000000000000000011
#define ll long long

ll H[M];
ll R[M];
ll N,W,L;
ll end = 1;

int check(ll t)
{
	ll sum=0;
	ll i;
	for(i=0;i<N;i++)
	{
		ll temp = H[i]+R[i]*t;
		if(temp>=L) sum += temp;
		if(sum>=W) return 1;
	}
	if(sum>=W) return 1;
	else return 0;
	
}

int main()
{
	scanf("%lld %lld %lld",&N,&W,&L);
	ll i;
	for(i=0;i<N;i++)
	{
		scanf("%lld %lld",&H[i],&R[i]);
	}
	ll start = -1;
	
	while(!check(end))
	{
		end *= 2;
		//printf("end: %d\n",end);
	}
	while(start<end)
	{
		if(check(0)) {
		end = 0;
		break;
	}
		ll mid = (start+end)/2;
		printf("%lld %lld %lld\n",start,mid,end);
		if(!check(mid)) start = mid+1;
		else end = mid;
	}
	printf("%lld\n",end);
	return 0;	
}
