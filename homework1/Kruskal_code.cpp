#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int INF = 0x3f3f3f3f;
int n,m,cnt=0,fa[N],sum=0;

struct edge{
	int u,v,w;
}a[N];

int cmp(const edge &a, const edge &b) {
    return a.w < b.w;
}

//并查集 
int find(int x) {
    return fa[x] == x ? x : find(fa[x]);
}

void merge(int x,int y){
	fa[find(y)] = find(x);
}

void init(){
	memset(a,INF,sizeof a);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
		
	for(int i=1;i<=n;i++) fa[i]=i;
}

void kruskal(){
	sort(a+1,a+m+1,cmp);
	
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break; //边数为点的个数减一时找到最短路 
		if(find(a[i].u) != find(a[i].v)){  //不相连 
			merge(a[i].u, a[i].v);  //加入并查集 
			cout << "v"<<a[i].u << "----v" << a[i].v << endl;
			sum += a[i].w;
			cnt++; 
		}	
	}
	cout<<sum;
} 

int main(){
	init();
		
	kruskal();
}
/*
输入： 
5 6
1 4 5
1 2 3
2 4 6
2 3 9
2 5 10
3 5 4
*/
