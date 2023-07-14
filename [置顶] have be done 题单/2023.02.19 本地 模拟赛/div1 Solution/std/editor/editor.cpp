#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500010
#define upmin(_a,_b) _a=min(_a,_b)
using namespace std;
namespace ywy{
    typedef unsigned char byte;
    void sget(char *s){
        int n=1;char c;while((c=getchar())||23333)if(c>='a'&&c<='z')break;
        s[n]=c-'a';n++;while((c=getchar())||23333){
            if(c>='a'&&c<='z')s[n]=c-'a',n++;else return;
        }
    }char str[N],anss[N];int dp[N][2];
    inline int getb(int x,int bit){
        byte *p=(byte*)&x;return(p[bit]);   
    }
    inline int setb(int x,int bit,int y){
        byte *p=(byte*)&x;p[bit]=y;return(x);   
    }
    inline int xchg(int x,int i,int j){
        byte *p=(byte*)&x;swap(p[i],p[j]);return(x);    
    }
    void ywymain(){
    	freopen("editor.in","r",stdin);
    	freopen("editor.out","w",stdout);
        int t;cin>>t;while(t){
            t--;int n,k;cin>>n>>k;sget(str);str[n+1]=str[n+2]=0;
            memset(dp,0x7f,sizeof(dp));dp[0][0]=str[1];
            for(register int i=1;i<=n;i++){
                int minn;if(i>3){
                    minn=min(getb(dp[i-1][0],3),getb(dp[i-1][1],3));
                }else minn=0;if(i>3)putchar(minn+'a');
                if(getb(dp[i-1][0],3)==minn){//now str[i] is on bit0
                    int me=(dp[i-1][0]<<8)|str[i+1];
                    upmin(dp[i][0],me);
                    upmin(dp[i][0],setb(me,1,(str[i]+1)%k));
                    upmin(dp[i][0],setb(me,1,(str[i]+k-1)%k));
                    if(i!=1)upmin(dp[i][0],xchg(me,1,2));
                    if(i!=n)upmin(dp[i][1],xchg(me,0,1));
                }if(getb(dp[i-1][1],3)==minn){//now str[i] is on bit1
                    int me=(dp[i-1][1]<<8)|str[i+1];upmin(dp[i][0],me);
                    upmin(dp[i][0],setb(me,2,(str[i]+1)%k));
                    upmin(dp[i][0],setb(me,2,(str[i]+k-1)%k));
                    if(i-1!=1)upmin(dp[i][0],xchg(me,2,3));
                    upmin(dp[i][0],xchg(me,1,2));   
                }
            }int ans=min(dp[n][0],dp[n][1]);if(n==1){
                putchar(getb(ans,1)+'a');   
            }if(n==2){
                putchar(getb(ans,2)+'a');putchar(getb(ans,1)+'a');  
            }if(n>=3){
                putchar(getb(ans,3)+'a');putchar(getb(ans,2)+'a');putchar(getb(ans,1)+'a'); 
            }cout<<endl;
        }
    }
}
int main(){
    ywy::ywymain();return(0);   
}
