#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 105;
int graph[N][N];
int n,m;
void floyd(){
	int s=1;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(graph[i][k]!=INF){
				for(int j=1;j<=n;j++){
						graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(graph[i][j]!=INF)
				printf("%d %d %d\n",i,j,graph[i][j]);
			else
				printf("%d %d INF\n",i,j);
		}
	}
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		if(n==0&&m==0) return 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) graph[i][j] = 0;
				else graph[i][j] = INF;
			}
		}
		while(m--){
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			graph[u][v] = w;
		}
		floyd();
	}
}
/*
input:
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/
