#include<cstdio>
#include<iostream>
#define R register int
using namespace std;
int n,a[1030]={1};
signed main() {
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	scanf("%d",&n);
	//for(R i=1;i<=500;i++) printf("%d ",a[i]); putchar('\n');
	for(R i=0;i<(1<<n);i++) {
		for(R j=1;j<(1<<n)-i;j++) printf(" "); 
		for(R j=i;j>=0;j--) a[j]^=a[j-1];
		if(!(i&1)) for(R j=0;j<=i;j++) a[j]?printf("/\\"):printf("  ");
		else for(R j=0;j<=i;j+=2) a[j]?printf("/__\\"):printf("    ");
		printf("\n");
	}
}
