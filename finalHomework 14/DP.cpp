#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+10;
string str1;
string str2;
int dp[N][N];
int temp;
void DP(){
	int n,m; //源串和目标串长度 
	n=str1.length();
	m=str2.length();
	//初始化
	//从源串(1-i)到目标串的(1-j)的最小操作次数
	for(int i=1;i<=n;i++){
		dp[i][0]=i; //删除i次得到目标串为空 
	}
	for(int j=1;j<=m;j++){
		dp[0][j]=j; //空的源串添加j次得到目标串
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(str1[i-1]==str2[j-1]){
				dp[i][j]=dp[i-1][j-1];
				//操作次数不变
			}else{
//				cout<< "dp[i][j-1]+1"<<dp[i][j-1]+1<<endl;
//				cout<< "dp[i-1][j-1]+1"<<dp[i-1][j-1]+1<<endl;
				temp=min(dp[i][j-1]+1,dp[i-1][j-1]+1);
				dp[i][j]=min(temp,dp[i-1][j]+1);
				//在原有最小操作次数上+1，并取操作次数最小值
			}
		}	
	}
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=m;j++){
//			cout<<dp[i][j]<<" "; 
//		}	
//		cout<<endl;
//	}
	cout<<"最小操作次数为："<<dp[n][m]<<endl; 
	return;
} 
int main(){
	freopen("input.txt","r",stdin); 
	//输入不为空串，源串和目标串为0时，退出程序 
	while(1){
		cin>>str1;
		cin>>str2;
		if(str1=="0"&&str2=="0") break;
		cout<<"源  串:"<<str1<<endl;
		cout<<"目标串:"<<str2<<endl;
		if(str1.compare(str2)==0){
			cout<<"最小操作次数为："<<0<<endl;
		}else{
			DP();
		}
		cout<<endl; 
	}
	return 0;
}
