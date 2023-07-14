#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010

const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

int i,j,n,m,tx,ty;
int dist[MAXN][MAXN];
char s[MAXN][MAXN];
char val;
pair<int,int> cur;
queue< pair<int,int> > q;

inline bool ok(int x,int y)
{
        return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() 
{
   freopen("bit.in","r",stdin);
    freopen("bit.out","w",stdout);
        memset(dist,255,sizeof(dist));
        scanf("%d%d",&n,&m);
        for (i = 1; i <= n; i++) scanf("%s",s[i]+1);
        for (i = 1; i <= n; i++)
        {
                for (j = 1; j <= m; j++)
                {
                        if (s[i][j] == '1')
                        {
                                q.push(make_pair(i,j));
                                dist[i][j] = 0;
                        }
                }
        }
        while (!q.empty())
        {
                cur = q.front();
                q.pop();
                for (i = 0; i < 4; i++)
                {
                        tx = cur.first + dx[i];
                        ty = cur.second + dy[i];
                        if (ok(tx,ty) && dist[tx][ty] == -1)
                        {
                                dist[tx][ty] = dist[cur.first][cur.second] + 1;
                                q.push(make_pair(tx,ty));
                        }
                }         
        }
        for (i = 1; i <= n; i++)
        {
                for (j = 1; j <= m; j++)
                {
                        printf("%d ",dist[i][j]);
                }
                printf("\n");
        }
        
        return 0;
    
}
 