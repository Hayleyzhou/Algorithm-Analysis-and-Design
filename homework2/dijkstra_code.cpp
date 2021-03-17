#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 105;

struct node
{
    int to,w,next;
}edge[N];

int head[N],cnt;
int dis[N],vis[N];
int n,m,s,t;
 
void init()
{
    memset(head,-1,sizeof head);
    memset(dis,INF,sizeof dis);
    memset(vis,0,sizeof vis);
    cnt = 0;
}
 
void add(int u,int v,int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt ++;
}
 
void dijkstra()
{
    dis[s] = 0;
    for(int i = 1; i <= n-1; i++)
    {
        int minn = INF, now;
        for(int j = 1; j <= n; j++) //找离源点最近的一个点
        {
            if(vis[j] == 0 && dis[j] < minn)
            {
                minn = dis[j];
                now = j;  //记录最近点
            }
        }
        cout<<now<<endl;
        vis[now] = 1; 
		//标记最近点
        for(int i = head[now]; i != -1; i = edge[i].next) //遍历以now为起点的边
        {
            int v = edge[i].to; //now->v的边
            if(dis[v] > dis[now] + edge[i].w) //判断松弛
            {
                dis[v] = dis[now] + edge[i].w; //松弛操作
            }
        }
        for(int i=1;i<=n;i++){
        	printf(" %d ",dis[i]);
		}
		cout<<endl;
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        init(); //初始化
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d",&u, &v, &w);
            add(u, v, w);  //加边
//            add(v, u, w);   有向图不需要 
        }
        s=1, t=n; //s起点，t终点
        dijkstra();
        printf("%d\n",dis[t]);
    }
}
/*
input:
8 11
1 2 1
2 4 2
3 1 2
4 3 1
5 4 2
4 6 8
6 5 2
5 7 2
7 6 3
7 8 3
8 6 2
*/ 
