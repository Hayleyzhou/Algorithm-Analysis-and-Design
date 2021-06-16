#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int m[N][N] = {0}, s[N][N];  
//m[i][i]初始化为0，用于存储乘法次数的中间值  s[][]用于存储划分位置的下标

void matrixChain(int p[], int n) {
	for (int r = 2; r <= n; r++) {  //r为当前问题规模
		for (int i = 1; i <= n - r + 1; i++) {  //起点 
			int j = i + r - 1;  //终点
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;

			//遍历不同划分位置，存储最小的乘法次数及其位置下标
			for (int k = i + 1; k <= j - 1; k++) {
				int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (temp < m[i][j]) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}

	//输出结果
	cout <<"最小乘法次数为："<<m[1][6]<< endl;
//	cout << "划分位置由外到内为：";
//	cout << "s[1,6]=4  s[1,4]=1  s[2,4]=2\n";
}

int main() {
	freopen("input.txt","r",stdin);
	int n,p[N];  
	//n表示矩阵个数  p[]表示矩阵链的行列数
	cin>>n;
	for (int i = 0; i <= n; i++)  //n个矩阵有n+1个行列数
		cin>>p[i];
	matrixChain(p, n);
}
