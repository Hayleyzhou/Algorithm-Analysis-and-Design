#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;


int main() {
	int m, n,sum;
	int f[N][N],dp[N][N],inv[N][N];
	
	scanf("%d %d", &m,&n);
	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &f[j][i]);

	//动态规划
	for (int k = 1; k <= n; k++) //第k个项目 
		for (int x = 1; x <= m; x++)  //加上k项目时，共分配的钱 
			for (int i = 0; i <= x; i++) // 项目k分配多少钱 
				if (dp[k - 1][x - i] + f[k][i] >= dp[k][x]) {
					dp[k][x] = dp[k - 1][x - i] + f[k][i];
					inv[k][x] = i;
				}
	cout <<"最大收益"<< dp[n][m] << "万" << endl;
	cout << "分配：\n";
	sum = m;
	for (int i = n; i >= 1;i--) {
		cout << "第" << i << "个项目分配" << inv[i][sum] << "万"<< endl;
		sum -= inv[i][sum];
	}
}
//input 
//5 4
//0 0 0 0
//11 0 2 20
//12 5 10 21
//13 10 30 22
//14 15 32 23
//15 20 40 24
