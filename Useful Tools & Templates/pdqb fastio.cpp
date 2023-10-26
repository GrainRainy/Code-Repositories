namespace IO{
	template<typename T> inline void rd(T &x){
		x=0;bool f=0;char c=0;
		while(c<'0'||c>'9') f|=c=='-',c=getchar();
		while('0'<=c&&c<='9') x=x*10+(c^48),c=getchar();
		x=f?-x:x;
	}
	template<typename T,typename ...Args> inline void rd(T &x,Args &...args){rd(x),rd(args...);}
	template<typename T> inline void wt(char c,T x){
		int stk[114],top=0;
		if(x<0) x=-x,putchar('-');
		do stk[++top]=x%10,x/=10; while(x);
		while(top) putchar(stk[top--]+'0');
		putchar(c);
	}
	template<typename T,typename ...Args> inline void wt(char c,T x,Args ...args){wt(c,x),wt(c,args...);}
	template<typename T,typename ...Args> inline void wt(char s,char c,T x,Args ...args){wt(c,x),wt(c,args...),putchar(s);}
};
using namespace IO;
