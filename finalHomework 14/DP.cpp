#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+10;
string str1;
string str2;
int dp[N][N];
int temp;
void DP(){
	int n,m; //Դ����Ŀ�괮���� 
	n=str1.length();
	m=str2.length();
	//��ʼ��
	//��Դ��(1-i)��Ŀ�괮��(1-j)����С��������
	for(int i=1;i<=n;i++){
		dp[i][0]=i; //ɾ��i�εõ�Ŀ�괮Ϊ�� 
	}
	for(int j=1;j<=m;j++){
		dp[0][j]=j; //�յ�Դ�����j�εõ�Ŀ�괮
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(str1[i-1]==str2[j-1]){
				dp[i][j]=dp[i-1][j-1];
				//������������
			}else{
//				cout<< "dp[i][j-1]+1"<<dp[i][j-1]+1<<endl;
//				cout<< "dp[i-1][j-1]+1"<<dp[i-1][j-1]+1<<endl;
				temp=min(dp[i][j-1]+1,dp[i-1][j-1]+1);
				dp[i][j]=min(temp,dp[i-1][j]+1);
				//��ԭ����С����������+1����ȡ����������Сֵ
			}
		}	
	}
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=m;j++){
//			cout<<dp[i][j]<<" "; 
//		}	
//		cout<<endl;
//	}
	cout<<"��С��������Ϊ��"<<dp[n][m]<<endl; 
	return;
} 
int main(){
	freopen("input.txt","r",stdin); 
	//���벻Ϊ�մ���Դ����Ŀ�괮Ϊ0ʱ���˳����� 
	while(1){
		cin>>str1;
		cin>>str2;
		if(str1=="0"&&str2=="0") break;
		cout<<"Դ  ��:"<<str1<<endl;
		cout<<"Ŀ�괮:"<<str2<<endl;
		if(str1.compare(str2)==0){
			cout<<"��С��������Ϊ��"<<0<<endl;
		}else{
			DP();
		}
		cout<<endl; 
	}
	return 0;
}
