#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
int vis[N],dis[N][N],a[N],au[N],n,m,ans=0; 
int u,v,w;
 
void init(){
	memset(dis,INF,sizeof dis);
	cin >> n >> m;  //n个点，m个边 
	for(int i = 1 ; i <= m;i++){
		cin>> u >> v >> w ;
		dis[u][v] = dis[v][u] = w;  //无向图 
	} 
	memset(vis,0,sizeof vis);
}

void prim(){
	vis[1] = 1;
	for(int i=1;i<=n;i++){
		a[i]=dis[1][i]; //存入和1相邻的点
		au[i]=1; 
	}
//	cout<<"V"<<v<<endl;
	for(int i=2;i<=n;i++){
		int minn=INF;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&a[j]<minn){
				minn = a[j];
				v = j;
				u = au[j];
			}
		}
		vis[v] = 1;
//		cout<<"V"<<v<<endl;
		cout<<"V"<<u<<"--V"<<v<<endl;
		ans += minn;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&a[j]>dis[v][j]){  //寻找点v相邻的边，值较小的记录 
				a[j] = dis[v][j];
				au[j]=v;  //记录顶点 
			}
		}
	}
}
int main(){
	init();
    prim();
    cout<<ans;
    return 0;
}
