//Stand up for the faith£¡
 
#include<bits/stdc++.h>
#define LL long long 
#define US unsigned
#define FRO freopen
#define FCO fclose 

using namespace std;

inline int read()
{
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
		if(ch=='-')w=-1;
		ch=getchar();
	}
    while(ch>='0'&&ch<='9')
    {
    	s=s*10+ch-'0';
		ch=getchar();
	}
    return s*w;
}

int n,m,add,kaga[100005];
int ans,numa=0,a[100005];

bool judge(int x) 
{
	int armos=0,cnt=1,pre=0;
	for(int i=1;i<=n;i++) 
	{
		if(armos+a[i]<=x) 
		armos+=a[i];
		else
		{
			armos=a[i];
			cnt++;
		}
	}
	return cnt<=m;
}

int main(void)
{
//	FRO("wage.in","r",stdin);
//    FRO("wage.out","w",stdout);
	n=read();m=read();
	// m+=1;
	for(int i=1;i<=n;i++) 
	{
		a[i]=read();
		add+=a[i];
		numa=max(numa,a[i]);
	}	
	int l=numa,r=add;
	while(l<=r) 
	{
		int czar=(l+r)/2;
		if(judge(czar)) 
		r=czar-1,ans=czar;
		else l=czar+1;
	}
	printf("%d",ans);
	return 0;
	FCO(stdin);FCO(stdout);
}

